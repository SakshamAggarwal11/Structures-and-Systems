CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic
TARGET := calculator_server
SRC := src/main.cpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
