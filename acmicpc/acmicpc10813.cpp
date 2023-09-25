#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = a;
}

int main()
{
    int N, M, basket[100];
    
    cin >> N >> M;
    for (int n = 0; n < N; ++n) { basket[n] = n + 1; }

    int i, j;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j;
        swap(basket[i - 1], basket[j - 1]);
    }

    for (int n = 0; n < N; ++n) { cout << basket[n] << ' '; }
}