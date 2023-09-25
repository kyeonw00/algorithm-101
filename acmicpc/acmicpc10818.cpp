#include <iostream>

using namespace std;

int min(const int a, const int b) { return a < b ? a : b; };

int max(const int a, const int b) { return a < b ? b : a; };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, val;
    int minVal = 1000000, maxVal = -1000000;

    cin >> N;
    for (int n = 0; n < N; ++n)
    {
        cin >> val;
        minVal = min(val, minVal);
        maxVal = max(val, maxVal);
    }

    cout << minVal << " " << maxVal;
}