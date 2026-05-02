#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cerrno>
#include <csignal>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

namespace fs = std::filesystem;

namespace {
constexpr int kPort = 8080;
const fs::path kWebRoot = fs::path("web");

std::string urlDecode(const std::string& value) {
    std::string decoded;
    decoded.reserve(value.size());
    for (size_t i = 0; i < value.size(); ++i) {
        const unsigned char ch = static_cast<unsigned char>(value[i]);
        if (ch == '%') {
            if (i + 2 >= value.size()) {
                throw std::runtime_error("Malformed percent-encoding");
            }
            auto hex = value.substr(i + 1, 2);
            char* end = nullptr;
            const long parsed = std::strtol(hex.c_str(), &end, 16);
            if (end == nullptr || *end != '\0') {
                throw std::runtime_error("Malformed percent-encoding");
            }
            decoded.push_back(static_cast<char>(parsed));
            i += 2;
        } else if (ch == '+') {
            decoded.push_back(' ');
        } else {
            decoded.push_back(static_cast<char>(ch));
        }
    }
    return decoded;
}

std::string trim(std::string text) {
    const auto begin = text.find_first_not_of(" \t\r\n");
    if (begin == std::string::npos) {
        return "";
    }
    const auto end = text.find_last_not_of(" \t\r\n");
    return text.substr(begin, end - begin + 1);
}

class ExpressionParser {
public:
    explicit ExpressionParser(std::string expression) : expression_(std::move(expression)) {}

    double parse() {
        position_ = 0;
        const double value = parseExpression();
        skipWhitespace();
        if (position_ != expression_.size()) {
            throw std::runtime_error("Unexpected trailing characters");
        }
        return value;
    }

private:
    double parseExpression() {
        double value = parseTerm();
        while (true) {
            skipWhitespace();
            if (match('+')) {
                value += parseTerm();
            } else if (match('-')) {
                value -= parseTerm();
            } else {
                break;
            }
        }
        return value;
    }

    double parseTerm() {
        double value = parseFactor();
        while (true) {
            skipWhitespace();
            if (match('*')) {
                value *= parseFactor();
            } else if (match('/')) {
                const double divisor = parseFactor();
                if (divisor == 0.0) {
                    throw std::runtime_error("Division by zero");
                }
                value /= divisor;
            } else {
                break;
            }
        }
        return value;
    }

    double parseFactor() {
        skipWhitespace();
        if (match('+')) {
            return parseFactor();
        }
        if (match('-')) {
            return -parseFactor();
        }
        if (match('(')) {
            const double value = parseExpression();
            skipWhitespace();
            if (!match(')')) {
                throw std::runtime_error("Missing closing parenthesis");
            }
            return value;
        }
        return parseNumber();
    }

    double parseNumber() {
        skipWhitespace();
        const size_t start = position_;
        bool hasDigit = false;
        bool hasDot = false;

        while (position_ < expression_.size()) {
            const unsigned char ch = static_cast<unsigned char>(expression_[position_]);
            if (std::isdigit(ch)) {
                hasDigit = true;
                ++position_;
            } else if (ch == '.' && !hasDot) {
                hasDot = true;
                ++position_;
            } else {
                break;
            }
        }

        if (!hasDigit) {
            throw std::runtime_error("Expected a number");
        }

        return std::stod(expression_.substr(start, position_ - start));
    }

    void skipWhitespace() {
        while (position_ < expression_.size() && std::isspace(static_cast<unsigned char>(expression_[position_]))) {
            ++position_;
        }
    }

    bool match(char expected) {
        if (position_ < expression_.size() && expression_[position_] == expected) {
            ++position_;
            return true;
        }
        return false;
    }

    std::string expression_;
    size_t position_ = 0;
};

std::string formatDouble(double value) {
    std::ostringstream out;
    out.setf(std::ios::fixed);
    out.precision(10);
    out << value;
    std::string text = out.str();
    while (!text.empty() && text.back() == '0') {
        text.pop_back();
    }
    if (!text.empty() && text.back() == '.') {
        text.pop_back();
    }
    if (text.empty()) {
        text = "0";
    }
    return text;
}

std::string statusText(int code) {
    switch (code) {
        case 200: return "OK";
        case 400: return "Bad Request";
        case 404: return "Not Found";
        case 500: return "Internal Server Error";
        default: return "OK";
    }
}

std::string contentTypeFor(const fs::path& file) {
    const auto extension = file.extension().string();
    if (extension == ".html") {
        return "text/html; charset=utf-8";
    }
    if (extension == ".css") {
        return "text/css; charset=utf-8";
    }
    if (extension == ".js") {
        return "application/javascript; charset=utf-8";
    }
    return "text/plain; charset=utf-8";
}

std::string readFile(const fs::path& file) {
    std::ifstream stream(file, std::ios::binary);
    if (!stream) {
        throw std::runtime_error("Unable to open file");
    }
    std::ostringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

std::string makeResponse(int code, const std::string& contentType, const std::string& body, bool includeBody = true) {
    std::ostringstream response;
    response << "HTTP/1.1 " << code << ' ' << statusText(code) << "\r\n";
    response << "Content-Type: " << contentType << "\r\n";
    response << "Content-Length: " << body.size() << "\r\n";
    response << "Connection: close\r\n\r\n";
    if (includeBody) {
        response << body;
    }
    return response.str();
}

std::string calculateExpression(const std::string& expr) {
    ExpressionParser parser(expr);
    return formatDouble(parser.parse());
}

std::string routeRequest(const std::string& request) {
    std::istringstream stream(request);
    std::string method;
    std::string target;
    std::string version;

    if (!(stream >> method >> target >> version)) {
        return makeResponse(400, "text/plain; charset=utf-8", "Malformed request");
    }

    const bool includeBody = method != "HEAD";
    if (method != "GET" && method != "HEAD") {
        return makeResponse(400, "text/plain; charset=utf-8", "Only GET and HEAD are supported");
    }

    const auto queryPos = target.find('?');
    const std::string path = queryPos == std::string::npos ? target : target.substr(0, queryPos);
    const std::string query = queryPos == std::string::npos ? "" : target.substr(queryPos + 1);

    if (path == "/api/calculate") {
        const std::string key = "expr=";
        if (query.rfind(key, 0) != 0) {
            return makeResponse(400, "text/plain; charset=utf-8", "Missing expr parameter");
        }
        try {
            const std::string expr = urlDecode(query.substr(key.size()));
            if (trim(expr).empty()) {
                return makeResponse(400, "text/plain; charset=utf-8", "Expression cannot be empty");
            }
            const std::string result = calculateExpression(expr);
            return makeResponse(200, "text/plain; charset=utf-8", result, includeBody);
        } catch (const std::exception& error) {
            return makeResponse(400, "text/plain; charset=utf-8", error.what(), includeBody);
        }
    }

    fs::path filePath = kWebRoot / (path == "/" ? "index.html" : path.substr(1));
    if (!fs::exists(filePath) || !fs::is_regular_file(filePath)) {
        return makeResponse(404, "text/plain; charset=utf-8", "Not found", includeBody);
    }

    try {
        return makeResponse(200, contentTypeFor(filePath), readFile(filePath), includeBody);
    } catch (const std::exception& error) {
        return makeResponse(500, "text/plain; charset=utf-8", error.what(), includeBody);
    }
}

int createServerSocket() {
    const int serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        throw std::runtime_error(std::string("socket failed: ") + std::strerror(errno));
    }

    int enable = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        ::close(serverSocket);
        throw std::runtime_error(std::string("setsockopt failed: ") + std::strerror(errno));
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(kPort);

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&address), sizeof(address)) < 0) {
        ::close(serverSocket);
        throw std::runtime_error(std::string("bind failed: ") + std::strerror(errno));
    }

    if (listen(serverSocket, 16) < 0) {
        ::close(serverSocket);
        throw std::runtime_error(std::string("listen failed: ") + std::strerror(errno));
    }

    return serverSocket;
}

}  // namespace

int main() {
    std::signal(SIGPIPE, SIG_IGN);

    if (!fs::exists(kWebRoot)) {
        std::cerr << "Missing web directory\n";
        return 1;
    }

    int serverSocket = -1;
    try {
        serverSocket = createServerSocket();
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }

    std::cout << "Calculator server running at http://localhost:" << kPort << std::endl;

    while (true) {
        sockaddr_in clientAddress{};
        socklen_t clientLength = sizeof(clientAddress);
        const int clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddress), &clientLength);
        if (clientSocket < 0) {
            continue;
        }

        std::string request;
        char buffer[4096];
        ssize_t received = 0;
        while ((received = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
            request.append(buffer, static_cast<size_t>(received));
            if (request.find("\r\n\r\n") != std::string::npos) {
                break;
            }
        }

        const std::string response = routeRequest(request);
        send(clientSocket, response.c_str(), response.size(), 0);
        ::close(clientSocket);
    }

    ::close(serverSocket);
    return 0;
}
