#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int A, B;
    for (int t = 1; t <= T; ++t)
    {
        cin >> A >> B;
        cout << "Case #" << t << ": " << (A + B) << '\n';
    }
}