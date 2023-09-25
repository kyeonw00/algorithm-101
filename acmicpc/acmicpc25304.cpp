#include <iostream>

using namespace std;
typedef long long lld;

int main()
{
    int X, N;
    cin >> X >> N;

    int prodNum, prodPrice;
    for (int n = 0; n < N; ++n)
    {
        cin >> prodNum >> prodPrice;
        X -= (prodNum * prodPrice);
    }

    if (X != 0)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}