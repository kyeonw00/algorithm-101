#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp1[1001];
int dp2[1001];

int main()
{
    int answer = 0;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= N; i++) 
    {
        dp1[i] = 1;
        
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        dp2[i] = 1;
        for (int j = N; j >= i; j--)
        {
            if (arr[j] < arr[i] && dp2[i] < dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    for (int i = 0; i <= N; i++)
    {
        if (answer < dp1[i] + dp2[i] - 1)
        {
            answer = dp1[i] + dp2[i] - 1;
        }
    }

    printf("%d", answer);

    return 0;
}