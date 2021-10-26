#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int b1, b2, b3;
    
    cin >> a;
    cin >> b;

    b3 = b / 100;
    b2 = (b % 100) / 10;
    b1 = b % 10;

    cout << a * b1 << endl;
    cout << a * b2 << endl;
    cout << a * b3 << endl;
    cout << a * b << endl;
}