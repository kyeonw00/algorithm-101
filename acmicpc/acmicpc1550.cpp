#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ll;

const int ASCII_OFFSET = 48;
const int DECIMAL_MAX = 9;
const int HEXADECIMAL_RANGE = 16;

int main() {
    string input;
    cin >> input;

    int decimal = 0;
    int digits = 1;

    for (int i = input.size() - 1; i >= 0; --i) {
        int hexadecimal = (char)input.at(i) - ASCII_OFFSET;

        if (hexadecimal >= HEXADECIMAL_RANGE)
        {
            hexadecimal = (DECIMAL_MAX + (hexadecimal - HEXADECIMAL_RANGE));
        }

        hexadecimal *= digits;
        decimal += hexadecimal;
        digits *= HEXADECIMAL_RANGE;

        // cout << input.at(i) << " is " << hexadecimal << " and sum is " << decimal << '\n';
    }

    cout << decimal;
}