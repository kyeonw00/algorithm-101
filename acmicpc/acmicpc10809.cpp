#include <iostream>
#include <string>

#define ALPHABET_ASCII_START 97
#define ALPHABET_ASCII_END 122

using namespace std;

int main()
{
    string s;
    s.reserve(100);

    cin >> s;

    int alphabetRangeSize = ALPHABET_ASCII_END - ALPHABET_ASCII_START;
    for (int i = 0; i <= alphabetRangeSize; ++i)
    {
        char currentAlpahbet = (char)(ALPHABET_ASCII_START + i);
        int j;
        bool didFind = false;
        for (j = 0; j < s.length(); ++j)
        {
            if (s.at(j) == currentAlpahbet)
            {
                didFind = true;
                break;
            }
        }

        cout << (didFind ? j : -1) << ' ';
    }
}