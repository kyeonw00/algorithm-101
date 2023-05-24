#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;

    int length = word.length();
    int lengthHalf = length / 2;
    bool isPalindrome = true;
    for (int i = 0; i < lengthHalf; i++)
    {
        if (word[i] != word[length - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    cout << isPalindrome << endl;
}