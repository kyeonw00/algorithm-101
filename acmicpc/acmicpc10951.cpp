#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    do {
        cin >> A >> B;

        if (cin.eof() || cin.fail())
        {
            break;
        }

        cout << (A + B) << '\n';
    } while (true);
}