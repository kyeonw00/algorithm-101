#include <iostream>

using namespace std;

const char* TYPE_NAME_LONG = "long";
const char* TYPE_NAME_INT = "int";
const int BYTE_SIZE_INT = 4;

int main()
{
    int N;
    cin >> N;

    N = (N % BYTE_SIZE_INT != 0) ? (N / BYTE_SIZE_INT + 1) : (N / BYTE_SIZE_INT);
    while (N > 0)
    {
        cout << TYPE_NAME_LONG << ' ';
        --N;
    }

    cout << TYPE_NAME_INT;
}