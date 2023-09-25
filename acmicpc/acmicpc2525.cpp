#include <iostream>

#define day_to_hour 24
#define hour_to_minute 60

using namespace std;

void addMinuteToTime(int &hour, int &minute, const int adjustTimeInMinute)
{
    int adjustedHour = hour + (adjustTimeInMinute / hour_to_minute);
    int adjustedMinute = minute + (adjustTimeInMinute % hour_to_minute);

    if (adjustedMinute >= hour_to_minute)
    {
        adjustedMinute -= hour_to_minute;
        adjustedHour++;
    }

    adjustedHour %= day_to_hour;

    hour = adjustedHour;
    minute = adjustedMinute;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    addMinuteToTime(A, B, C);
    cout << A << " " << B;
}