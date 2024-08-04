#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string inputStr;
    while (getline(cin, inputStr))
    {
        if (inputStr.empty())
        {
            break;
        }
        
        cout << inputStr << "\n";
        cout.flush();
    }

    return 0;
}