#include <string>
#include <array>

using namespace std;

const array<int, 13> daysInMonths
{
    0,                          // padding
    31, 29, 31, 30, 31, 30, 31, // 1 ~ 7
    31, 30, 31, 30, 31          // 8 ~ 12
};

const array<string, 7> dayOfWeeks
{
    "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"
};

string solution(int a, int b)
{
    int month = 1;
    int days = 0;
    while (month < a)
    {
        days += daysInMonths[month];
        ++month;
    }
    
    days += b - 1;
    
    return dayOfWeeks[days % 7];
}