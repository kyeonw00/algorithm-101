#include <iostream>
#include <algorithm>

using namespace std;

struct Matrix
{
    int row;
    int column;
};

const int INF = 1000000000;
const int MAX_MATRIX_COUNT = 501;

int main()
{
    int N;
    cin >> N;

    Matrix matrices[MAX_MATRIX_COUNT];
    int dp[MAX_MATRIX_COUNT][MAX_MATRIX_COUNT];
    for (int n = 1; n <= N; ++n)
    {
        cin >> matrices[n].row >> matrices[n].column;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; i + j <= N; j++)
        {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (matrices[j].row * matrices[k].column * matrices[i + j].column));
            }
        }
    }

    cout << dp[1][N];
}