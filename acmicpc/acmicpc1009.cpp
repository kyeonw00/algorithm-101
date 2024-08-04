#include <iostream>

using namespace std;

int main()
{
    // don't sync with stdio buffer with iostream's
    // reduces buffer size and increase handling speed
    ios_base::sync_with_stdio(false);

    // untie cin and cout flushing action
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int a, b, dataAmount;
    for (int t = 0; t < T; ++t)
    {
        cin >> a >> b;
        
        dataAmount = a;
        for (int i = 2; i <= b; ++i)
        {
            dataAmount = dataAmount * a % 10;
        }

        dataAmount %= 10;
        if (dataAmount == 0) { dataAmount = 10; }
        cout << dataAmount << '\n';
    }
}