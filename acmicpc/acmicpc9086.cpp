#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string testCase;
    testCase.reserve(1000);

    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        cin >> testCase;
        cout << testCase.front() << testCase.back() << '\n';
    }
}