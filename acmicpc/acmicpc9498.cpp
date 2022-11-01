#include<iostream>
#define A_GRADE_SCORE 90
#define B_GRADE_SCORE 80
#define C_GRADE_SCORE 70
#define D_GRADE_SCORE 60

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int score;
    cin >> score;

    if (score >= A_GRADE_SCORE)
    {
        cout << 'A' << endl;
        return 0;
    }

    if (score >= B_GRADE_SCORE)
    {
        cout << 'B' << endl;
        return 0;
    }

    if (score >= C_GRADE_SCORE)
    {
        cout << 'C' << endl;
        return 0;
    }

    if (score >= D_GRADE_SCORE)
    {
        cout << 'D' << endl;
        return 0;
    }

    cout << 'F' << endl;
}