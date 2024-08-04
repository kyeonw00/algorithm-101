#include <iostream>
#include <cmath>

using namespace std;

// Preface:
//  - distance between each circles called D
//  - sum of distance to target from each circle's center called distDeltaSum
//  - difference of distance to target from each circle's center called distDeltaDiff
//      - distDeltaDiff is always positive number(absolute number)

// Case 1: No intersections
//  - When D is bigger than distDeltaSum
//  - (or) When D is smaller than distDeltaDiff

// Case 2: One intersection
//  - When D is equals to distDeltaSum
//  - (or) When D is equals to distDeltaDiff

// Case 3: Two intersections
//  - When D is bigger than distDeltaDiff
//  - (and) When D is smaller than distDeltaSum

// Case 4: Infinite intersections
//  - When D is zero (positioned in same coordinates)
//  - (and) distance to target from each circle's center are equal

// represents turret's position and distance to target
struct CoordinateInfo
{
    int x, y;
    int r; // distance to target
};

int countIntersection(const CoordinateInfo coord1, const CoordinateInfo coord2)
{
    double distBetweenTurret = sqrt(pow(coord2.x - coord1.x, 2) + pow(coord2.y - coord1.y, 2));

    // when the turrets are located at the same position
    // and the range also same
    if (distBetweenTurret == 0 && coord1.r == coord2.r)
    {
        return -1;
    }

    // when the turrets are located outside or inside each other
    // with no intersections
    if (distBetweenTurret > (coord1.r + coord2.r) ||
        distBetweenTurret < abs(coord1.r - coord2.r))
    {
        return 0;
    }

    if (distBetweenTurret == (coord1.r + coord2.r) ||
        distBetweenTurret == abs(coord1.r - coord2.r))
    {
        return 1;
    }

    return 2;
}

int main()
{
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int i = 0;
    CoordinateInfo coord1, coord2;
    while (i < T)
    {
        cin >> coord1.x >> coord1.y >> coord1.r >> coord2.x >> coord2.y >> coord2.r;
        cout << countIntersection(coord1, coord2) << '\n';

        i++;
    }
}