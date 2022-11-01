#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        for (int r = 0; r <= i; ++r)
        {
            cout << '*';
        }

        cout << endl;
    }
}