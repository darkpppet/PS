#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 3> sides;
    cin >> sides[0] >> sides[1] >> sides[2];

    ranges::sort(sides);

    sides[2] = min(sides[2], sides[0] + sides[1] - 1);

    cout << sides[0] + sides[1] + sides[2];
    return 0;
}