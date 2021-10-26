#include <iostream>
#include <algorithm>

using namespace std;

bool Less(int *a, int *b)
{
    return a[0] < b[0];
}

int Max(int a, int b) 
{
    return a > b ? a : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int cableCount;

    cin >> cableCount;
    int connections[cableCount][2];
    int dp[cableCount];

    for (int i = 0; i < cableCount; i++)
    {
        cin >> connections[i][0] >> connections[i][1];
    }
    sort(connections, connections + cableCount);

    for (int i = 0; i < cableCount; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (dp[j] + 1 > dp[i] && connections[i][1] > connections[j][1])
                dp[i] = dp[j] + 1;
        }
        answer = Max(answer, dp[i]);
    }
    
    cout << cableCount - answer << "\n";
    cout.flush();
    return 0;
}