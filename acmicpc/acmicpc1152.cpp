#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputStr;
    getline(cin, inputStr);

    if (inputStr.length() == 1 && inputStr[0] == ' ')
    {
        cout << 0;
        return 0;
    }

    int wordCount = 1;
    for (int i = 1; i < inputStr.length() - 1; i++)
    {
        if (inputStr[i] == ' ')
        {
            wordCount++;
        }
    }

    cout << wordCount;

    return 0;

}
