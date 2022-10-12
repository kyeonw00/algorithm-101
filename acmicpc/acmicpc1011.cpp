#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, X, Y;
    int distance, squareRoot, result;

    cin >> T;

    do {
        cin >> X >> Y;
        distance = Y - X;
        squareRoot = sqrt(distance);
        
        if (pow(squareRoot, 2) == distance) {
            result = 2 * squareRoot - 1;
        }
        else {
            result = 2 * squareRoot;
        }

        if (distance > (squareRoot * (squareRoot + 1))) {
            result++;
        }

        cout << result << endl;
    } while (--T);
}
