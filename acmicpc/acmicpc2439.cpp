#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1, r = 0; i <= N; ++i)
    {
        for (r = 0; r < N - i; ++r) cout << ' ';
        for (; r < N; ++r) cout << '*';

        cout << '\n';
    }
}