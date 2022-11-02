#include <iostream>
using namespace std;

int VISITED[5001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int N;
    cin >> N;

    VISITED[3] = 1;
    VISITED[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        if (VISITED[i - 3])
        {
            VISITED[i] = VISITED[i - 3] + 1;
        }

        if (VISITED[i - 5])
        {
            VISITED[i] = VISITED[i] ? min(VISITED[i], VISITED[i - 5] + 1) : VISITED[i - 5] + 1;
        }
    }

    cout << (VISITED[N] == 0 ? -1 : VISITED[N]);
}