#include <iostream>

using namespace std;

int reverse(int num)
{
    int reversedNum = 0;
    while (num > 0)
    {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    return reversedNum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num1, num2;
    cin >> num1 >> num2;

    int reversedNum1 = reverse(num1);
    int reversedNum2 = reverse(num2);

    cout << (reversedNum1 > reversedNum2 ? reversedNum1 : reversedNum2) << "\n";

    return 0;
}