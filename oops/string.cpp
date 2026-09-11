// saksham aggarwal
// btech cse , section-b
#include <iostream>
#include <string>
using namespace std;
int splitIntoWords(string sentence, string word[])
{
    int wordcount = 0;
    string currentword = "";
    for (int i = 0; i < sentence.length(); i++)
    {
        char ch = sentence[i];
        if (ch != ' ')
        {
            currentword = currentword + ch;
        }
        else
        {
            if (!currentword.empty()) // Handle consecutive spaces safely
            {
                word[wordcount] = currentword;
                wordcount++;
                currentword = "";
            }
        }
    }
    if (!currentword.empty())
    {
        word[wordcount] = currentword;
        wordcount++;
    }
    return wordcount;
}
void wordlengtharray(string word[], int wordcount, int length[])
{
    for (int i = 0; i < wordcount; i++)
    {
        length[i] = word[i].length();
    }
}
void sort(int wordcount, int length[], string word[])
{
    for (int i = 0; i < wordcount - 1; i++)
    {
        for (int j = 0; j < wordcount - i - 1; j++)
        {
            if (length[j] > length[j + 1])
            {
                // Swap oflengths
                int temp = length[j];
                length[j] = length[j + 1];
                length[j + 1] = temp;
                
                // Swap off word
                string tempw = word[j];
                word[j] = word[j + 1];
                word[j + 1] = tempw;
            }
        }
    }
}
int main()
{
    string sentence;
    string word[100];
    int length[100];
    cout << "enter the sentence-:";
    getline(cin, sentence);
    int wordcount = splitIntoWords(sentence, word);
    wordlengtharray(word, wordcount, length);
    cout << "total words in the string is-:" << wordcount << endl;
    if (wordcount > 0)
    {
        cout << "len of first word-: " << length[0] << endl;
        sort(wordcount, length, word);
        cout << "sorting acc to len-:"<< endl;
        for (int i = 0; i < wordcount; i++)
        {
            cout << word[i]<< " \n" << length[i] << endl;
        }
    }
    return 0;
}