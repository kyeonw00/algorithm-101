#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[100];

    int N, M;
    cin >> N >> M;
    for (int n = 0; n < N; ++n)
    {
        arr[n] = n + 1;
    }

    int i, j;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j;

        i--;
        j--;

        int middleIndex = (j - i) / 2;
        for (int attempt = 0; attempt <= middleIndex; ++attempt)
        {
            swap(arr[i + attempt], arr[j - attempt]);
        }
    }

    for (int n = 0; n < N; ++n)
    {
        cout << arr[n] << ' ';
    }
}