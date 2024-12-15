#include <iostream>

using namespace std;

int main()
{
    int value;
    int maxValue = -1;
    int tX, tY;

    for (int y = 1; y < 10; y++)
    {
        for (int x = 1; x < 10; x++)
        {
            cin >> value;

            if (value <= maxValue)
            {
                continue;
            }

            maxValue = value;
            tX = x;
            tY = y;
        }
    }

    cout << maxValue << '\n' << tY << ' ' << tX;
}