#include <iostream>

using namespace std;

const int TEST_CASE_COUNT = 9;

int main()
{
    int maxVal = 0, inputVal, maxValIndex = 0;
    for (int i = 0; i < TEST_CASE_COUNT; ++i)
    {
        cin >> inputVal;

        if (maxVal < inputVal)
        {
            maxVal = inputVal;
            maxValIndex = i + 1;
        }
    }

    cout << maxVal << '\n' << maxValIndex;
}