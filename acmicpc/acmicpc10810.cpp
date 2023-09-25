#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int basket[100] = { 0, };

    cin >> N >> M;

    int i, j, k;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j >> k;
        for (; i <= j; ++i) { basket[i - 1] = k; }
    }

    for (int n = 0; n < N; ++n)
    {
        cout << basket[n] << " ";
    }
}