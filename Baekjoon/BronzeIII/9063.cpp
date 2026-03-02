#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << (maxX - minX) * (maxY - minY);
    return 0;
}