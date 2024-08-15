#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int totalLineCount = 2 * N - 1;
    int spaceCount, starCount;
    for (int i = 0; i < totalLineCount; i++)
    {
        spaceCount = abs(N - i - 1);
        for (int j = 0; j < spaceCount; j++)
        {
            cout << " ";
        }

        starCount = 2 * N - 1 - 2 * spaceCount;
        for (int j = 0; j < starCount; j++)
        {
            cout << "*";
        }

        cout << '\n';
    }
}