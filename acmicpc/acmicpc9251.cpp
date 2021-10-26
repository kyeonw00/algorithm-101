#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 1000;

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    char string1[MAX_SIZE];
    char string2[MAX_SIZE];

    cin >> string1 >> string2;

    int string1Length = strlen(string1);
    int string2Length = strlen(string2);
    int dp[string1Length + 1][string2Length + 1] = {{0, 0}};

    for (int i = 1; i <= string1Length; i++)
    {
        for (int j = 1; j <= string2Length; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[string1Length][string2Length];
    cout.flush();
    return 0;
}