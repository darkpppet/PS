#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int c;
    cin >> c;

    int minD = numeric_limits<int>::max();
    int maxD = numeric_limits<int>::min();

    for (int i = 0; i < c; i++)
    {
        int d;
        cin >> d;

        minD = min(minD, d);
        maxD = max(maxD, d);
    }

    cout << minD * maxD;

    return 0;
}