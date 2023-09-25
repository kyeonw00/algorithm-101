#include <iostream>
#include <string>

using namespace std;

int charToInt(const char character) { return character - '0'; }

int main()
{
    int N;
    cin >> N;

    string inputString;
    cin >> inputString;

    int summary = 0;
    for (int i = 0; i < inputString.length(); ++i)
    {
        summary += charToInt(inputString.at(i));
    }

    cout << summary;
}