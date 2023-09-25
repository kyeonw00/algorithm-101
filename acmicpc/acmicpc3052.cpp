#include <iostream>
#define DIVIDER 42

using namespace std;

int main()
{
    int remains[42] = { 0 };
    int inputValue;

    for (int i = 0; i < 10; ++i)
    {
        cin >> inputValue;
        remains[inputValue % DIVIDER]++;
    }

    int count = 0;
    for (int i = 0; i < 42; ++i)
    {
        if (remains[i] != 0)
        {
            ++count;
        }
    }

    cout << count;
}