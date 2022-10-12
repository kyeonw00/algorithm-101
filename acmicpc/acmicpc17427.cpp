#include <iostream>

using namespace std;

long long g(int n)
{
    long long totalSum = 0;

    for (int i = 1; i <= n; i++)
    {
        totalSum += (n / i) * i;
    }

    return totalSum;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N;
    long long answer = 0;

    cin >> N;

    answer = g(N);

    cout << answer << endl;
    return 0;
}