#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    while (true)
    {
        array<int, 3> sides;
        cin >> sides[0] >> sides[1] >> sides[2];

        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
            return 0;

        ranges::sort(sides);

        if (sides[0] + sides[1] <= sides[2])
        {
            cout << "Invalid" << '\n';
            continue;
        }

        if (sides[0] == sides[1] && sides[1] == sides[2])
        {
            cout << "Equilateral" << '\n';
            continue;
        }

        if (sides[0] == sides[1] || sides[1] == sides[2])
        {
            cout << "Isosceles" << '\n';
            continue;
        }

        cout << "Scalene" << '\n';
    }
}