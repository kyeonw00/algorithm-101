#include <iostream>

using namespace std;

int dp[1000001] = {0, 1, 2};

int main()
{
    int N;
    long answe = 0;

    scanf("%d", &N);

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= 15746;
    }

    printf("%d", dp[N]);
    return 0;
}