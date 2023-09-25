#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int studentArr[30] = { 0 };

    int n;
    for (int i = 0; i < 28; ++i)
    {
        cin >> n;
        studentArr[n - 1] = 1;
    }

    for (int i = 0; i < 30; ++i)
    {
        if (studentArr[i] == 0)
        {
            cout << (i + 1) << '\n';
        }
    }
}