#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull fibonacci(ull n, const ull MOD)
{
    vector<ull> fibonacciSequence = { 0, 1 };
    const ull fisanoPeriodSize = 150000;

    for (ull i = 2; i < fisanoPeriodSize; ++i)
    {
        fibonacciSequence.push_back((fibonacciSequence[i - 1] + fibonacciSequence[i - 2]) % MOD);
    }

    return fibonacciSequence[n % fisanoPeriodSize];
}

int main()
{
    ull n;
    const ull MOD = 1000000;
    cin >> n;
    cout << fibonacci(n, MOD);
    return 0;
}