#include <iostream>

using namespace std;

int main()
{
    int paperCount;
    cin >> paperCount;

    int canvas[101][101] = { 0, };
    int leftOffset;
    int bottomOffset;
    int area = 0;
    for (int i = 0; i < paperCount; i++)
    {
        cin >> leftOffset >> bottomOffset;

        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                if (canvas[bottomOffset + y][leftOffset + x] == 1)
                {
                    continue;
                }

                area++;
                canvas[bottomOffset + y][leftOffset + x] = 1;
            }
        }
    }

    cout << area;
    return 0;
}