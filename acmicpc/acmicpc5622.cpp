#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int offset = 3;
    char asciiOffset = 'A' / 3;

    string inputStr;
    cin >> inputStr;

    int requiredTime = 0;
    for (auto& c : inputStr)
    {
        float delta = static_cast<float>(c - 'A');

        if (c >= 'P')
        {
            delta = floor(delta / 3.f + 2.f);

            if (c == 'S' || c == 'V' || c == 'Y' || c == 'Z')
            {
                delta -= 1;
            }
        }
        else
        {
            delta = floor(delta / 3.f + 2.f);
        }
        
        requiredTime += (delta + 1);
    }

    cout << requiredTime;
    cout.flush();

    return 0;
}