#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix getIdentityMatrix(const int size)
{
    matrix result(size, vector<ll>(size));

    for (int i = 0; i < size; ++i)
        result[i][i] = 1;

    return result;
}

matrix operator * (const matrix& lhs, const matrix& rhs)
{
    const int N = lhs.size();
    const int M = rhs[0].size();

    matrix result(N, vector<ll>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j) 
        {
            for (int k = 0; k < N; ++k)
            {
                result[i][j] += lhs[i][k] * rhs[k][j];
            }

            result[i][j] %= 1000;
        }
    }

    return result;
}

matrix power(matrix& base, ll exponent)
{
    if (exponent == 0)
    {
        return getIdentityMatrix(base.size());
    }

    if (exponent % 2 == 1)
    {
        return base * power(base, exponent - 1);
    }

    matrix mat = base * base;
    return power(mat, exponent / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, B;
    cin >> N >> B;

    const int MOD = 1000;

    matrix A(N, vector<ll>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    matrix answer = power(A, B);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }
}