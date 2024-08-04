#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    int repeatCount;
    string inputStr;
    for (int i = 0; i < testCase; i++)
    {
        cin >> repeatCount >> inputStr;

        for (int j = 0; j < inputStr.length(); j++)
        {
            for (int k = 0; k < repeatCount; k++)
            {
                cout << inputStr[j];
            }
        }

        cout << "\n";
        cout.flush();
    }


    return 0;
}