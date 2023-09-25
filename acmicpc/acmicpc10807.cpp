#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, v, vCount = 0, arr[100];

    cin >> N;
    for (int n = 0; n < N; ++n)
    {
        cin >> arr[n];
    }

    cin >> v;
    for (int n = 0; n < N; ++n)
    {
        if (arr[n] == v)
        {
            ++vCount;
        }
    }

    cout << vCount;
}