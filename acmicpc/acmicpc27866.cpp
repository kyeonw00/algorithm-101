#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int i;
    
    S.reserve(1000);

    cin >> S;
    cin >> i;
    cout << S.at(i - 1);
}