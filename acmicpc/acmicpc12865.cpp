#include <iostream>

using namespace std;

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int item[101][2];
    int dp[101][100001];

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < item[i][0])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else 
            {
                dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - item[i][0]] + item[i][1]);
            }
        }
    }

    cout << dp[N][K];
    return 0;
}