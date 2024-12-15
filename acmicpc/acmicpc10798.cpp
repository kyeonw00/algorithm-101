#include <iostream>

using namespace std;

int main()
{
    string buffer[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> buffer[i];
    }

    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (buffer[y].length() <= x)
            {
                continue;
            }

            cout << buffer[y][x];
        }
    }

    return 0;
}