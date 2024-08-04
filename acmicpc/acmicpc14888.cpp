#include <iostream>
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

using namespace std;

int min(const int a, const int b) { return a < b ? a : b; }

int max(const int a, const int b) { return a < b ? b : a; }

void readParameter(int& N, int * arr, int * operators)
{
    cin >> N;

    for (int n = 0; n < N; ++n)
    {
        cin >> arr[n];
    }

    cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];
}

void doOperation(
    const int * const numbers,
    const int numberCount,
    int stepCount,
    int delta,
    int * const operators,
    int& minResult,
    int& maxResult)
{
    if (stepCount == numberCount)
    {
        maxResult = max(delta, maxResult);
        minResult = min(delta, minResult);
        return;
    }

    for (int operatorIndex = 0; operatorIndex < 4; ++operatorIndex)
    {
        if (operators[operatorIndex] <= 0)
        {
            continue;
        }

        --operators[operatorIndex];
        switch (operatorIndex)
        {
            case ADD:
                doOperation(numbers, numberCount, stepCount + 1, delta + numbers[stepCount], operators, minResult, maxResult);
                break;
            case SUB:
                doOperation(numbers, numberCount, stepCount + 1, delta - numbers[stepCount], operators, minResult, maxResult);
                break;
            case MUL:
                doOperation(numbers, numberCount, stepCount + 1, delta * numbers[stepCount], operators, minResult, maxResult);
                break;
            case DIV:
                doOperation(numbers, numberCount, stepCount + 1, delta / numbers[stepCount], operators, minResult, maxResult);
                break;
        }
        ++operators[operatorIndex];
    }
}

int main()
{
    int N, ARR[11], OPERATORS[4];

    readParameter(N, ARR, OPERATORS);

    int minResult = 2147483647;
    int maxResult = -2147483647;
    int stepCount = 0;
    int delta = ARR[0];

    doOperation(ARR, N, stepCount + 1, delta, OPERATORS, minResult, maxResult);

    cout << maxResult << '\n' << minResult;
}