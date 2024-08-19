#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    string str;
    int groupWordCount = 0;
    while (N--)
    {
        getline(cin, str);
        bool isGroupWord = true;
        int alphabet[26] = { 0, };

        for (auto it = str.begin(); it != str.end(); ++it)
        {
            int index = *it - 'a';
            
            if (alphabet[index] == 0)
            {
                alphabet[index]++;
            }
            else if (alphabet[index] > 0 && *(it - 1) != *it)
            {
                isGroupWord = false;
                break;
            }
        }

        if (isGroupWord)
        {
            groupWordCount++;
        }
    }

    cout << groupWordCount;
}