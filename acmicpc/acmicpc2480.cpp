#include <iostream>

using namespace std;

int max(const int a, const int b) { return a > b ? a : b; }

int compare(const int a, const int b, const int c, int& duplicatedNumber)
{
    if (a == b && b == c)
    {
        duplicatedNumber = a;
        return 1;
    }
    else if (a == b || a == c)
    {
        duplicatedNumber = a;
        return 2;
    }
    else if (b == c)
    {
        duplicatedNumber = b;
        return 2;
    }

    duplicatedNumber = max(a, max(b, c));
    return 3;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int reward;
    int praiseCase = compare(a, b, c, reward);

    switch (praiseCase)
    {
        case 1: reward = 10000 + (reward * 1000); break;
        case 2: reward = 1000 + (reward * 100); break;
        case 3: reward *= 100; break;
    }

    cout << reward;
}