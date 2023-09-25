#include <iostream>

using namespace std;

int main()
{
    string word;
    word.reserve(100);

    cin >> word;
    cout << word.length();
}