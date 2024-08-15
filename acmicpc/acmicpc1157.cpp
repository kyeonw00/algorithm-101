#include <iostream>
#include <string>

using namespace std;

bool compare(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second > b.second;
}

int main()
{
    string str;
    getline(cin, str);

    int charCount[26] = { 0, };
    for (auto& c : str)
    {
        charCount[toupper(c) - 'A']++;
    }

    bool isHighestDuplicated = false;
    int maxCountIndex = -1;
    int maxCount = -1;
    for (int i = 0; i < 26; i++)
    {
        if (maxCount == charCount[i])
        {
            isHighestDuplicated = true;
        }
        else if (maxCount < charCount[i])
        {
            isHighestDuplicated = false;
            maxCount = charCount[i];
            maxCountIndex = i;
        }
    }

    if (isHighestDuplicated)
    {
        cout << "?";
    }
    else
    {
        cout << (char)(maxCountIndex + 'A');
    }
}