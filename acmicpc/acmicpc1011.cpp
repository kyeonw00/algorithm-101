#include <iostream>
#include <math.h>

using namespace std;

// Preface:
//  - for each distance, the pattern is matching with following rules
//      1. every steps can move distance between (k-1) to (k+1), relative to previously moved distance k.
//      2. the initial and final movable distance is always 1

// step 1:
//      if test some cases, it would be looks like following:
//      distance = 1, result = 1 (1)
//      distance = 2, result = 2 (1, 1)
//      distance = 3, result = 3 (1, 1, 1)
//      distance = 4, result = 3 (1, 2, 1)
//      distance = 5, result = 4 (1, 2, 1, 1)
//      distance = 6, result = 4 (1, 2, 2, 1)
//      distance = 7, result = 5 (1, 2, 2, 1, 1)
//      distance = 8, result = 5 (1, 2, 2, 2, 1)
//      distance = 9, result = 5 (1, 2, 3, 2, 1)
//      distance = 10, result = 6 (1, 2, 3, 2, 1, 1) ...

// step 2:
//      consider previous step's simulation, after passing a squared number(e.i. 4),
//      the result step count increases by 1

// step 3:
//      additionally, after passing a middle value of two squared number
//      the result step count increases by 1

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int X, Y, distance, squareRoot, result;
    for (int t = 0; t < T; ++t) {
        cin >> X >> Y;
        distance = Y - X;
        squareRoot = sqrt(distance);

        // if distance does equals to squared number of its floored square root number => (sqrt * 2) - 1
        // for other cases, => (sqrt * 2)
        if (pow(squareRoot, 2) == distance) { result = 2 * squareRoot - 1; }
        else { result = 2 * squareRoot; }

        if (distance > (squareRoot * (squareRoot + 1))) { result++; }

       cout << result << '\n';
    }
}