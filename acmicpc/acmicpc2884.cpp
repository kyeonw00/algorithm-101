#include <iostream>
#define hour_to_minute 60
#define day_to_hour 24
#define shift_minute 45

using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;

    m -= shift_minute;
    if (m < 0)
    {
        m += hour_to_minute;
        --h;

        if (h < 0)
        {
            h += day_to_hour;
        }
    }

    cout << h << " " << m;
}