#include <iostream>

using namespace std;

int main()
{
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if (a1 > c)
    {
        cout << 0;
        return 0;
    }

    if (a1 * n0 + a0 > c * n0)
        cout << 0;
    else
        cout << 1;

    return 0;
}