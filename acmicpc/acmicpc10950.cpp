#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int a, b;
    for (int t = 0; t < T; ++t)
    {
        cin >> a >> b;
        cout << (a + b) << '\n';
    }
}