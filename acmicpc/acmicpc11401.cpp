#include <iostream>

using namespace std;

typedef long long ll;

ll power(ll base, ll exponent, ll mod)
{
    if (exponent == 0)
        return 1;

    ll half = power(base, exponent / 2, mod) % mod;

    if (exponent % 2 == 1)
    {
        return ((half * half) % mod) * (base % mod);
    }

    return (half * half) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const ll MOD = 1000000007;

    int N, K;
    cin >> N >> K;

    ll factorialOfK = 1;
    ll factorialOfN = 1;
    for (int i = 1; i <= K; ++i)
        factorialOfK = (factorialOfK * i) % MOD;
    for (int i = N; i >= N - K + 1; --i)
        factorialOfN = (factorialOfN * i) % MOD;

    ll answer = (factorialOfN % MOD) * (power(factorialOfK, MOD - 2, MOD) % MOD) % MOD;
    cout << answer;
}

// reference
// - binomial coefficient
// - fermat's little theorem
// - modular arithmetic