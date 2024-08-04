#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<int>> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            higher.push(num);

        if (lower.size() < higher.size())
        {
            lower.push(higher.top());
            higher.pop();
        }
        else if (lower.size() > higher.size() + 1)
        {
            higher.push(lower.top());
            lower.pop();
        }

        cout << lower.top() << '\n';
    }

    return 0;
}