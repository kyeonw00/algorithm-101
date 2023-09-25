#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> croatiaCharacter = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string str;
    cin >> str;

    int charCount = 0;
    int i = str.length() - 1;
    int compareOffset;

    while (i >= 0)
    {
        for (const string& character : croatiaCharacter)
        {
            compareOffset = i - character.length() + 1;

            if (compareOffset >= 0 &&
                str.compare(compareOffset, character.length(), character) == 0)
            {
                i = compareOffset;
                break;
            }
        }

        ++charCount;
        --i;
    }

    cout << charCount << endl;
}