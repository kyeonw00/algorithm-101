#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, num;
    cin >> N;

    std::vector<int> arr;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << '\n';
    }
}