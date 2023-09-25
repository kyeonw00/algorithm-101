#include <iostream>

using namespace std;

int max(const int a, const int b) { return a < b ? b : a; }

int main()
{
    int N, scores[1000];
    int M = 0;
    cin >> N;

    for (int n = 0; n < N; ++n)
    {
        cin >> scores[n];
        M = max(M, scores[n]);
    }

    float average = 0;
    for (int n = 0; n < N; ++n)
    {
        average += ((float)scores[n] / (float)M) * 100.0f;
    }
    average /= N;
    cout << average;
}