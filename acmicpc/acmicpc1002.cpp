#include <iostream>
#include <cmath>

using namespace std;

int T;
int x_1, y_1, r_1;
int x_2, y_2, r_2;

int CheckIntersection(int x_1, int y_1, int r_1, int x_2, int y_2, int r_2)
{
    double d = sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
    int diff = abs(r_1 - r_2);
    int sum = r_1 + r_2;

    if (d == 0 && diff == 0)
    {
        return -1;
    }
    else if (d > sum || d < diff)
    {
        return 0;
    }
    else if (d == diff || d == sum)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    int i = 0;
    scanf("%d", &T);

    while (i < T)
    {
        scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
        printf("%d\n", CheckIntersection(x_1, y_1, r_1, x_2, y_2, r_2));
        i++;
    }

    return 0;
}