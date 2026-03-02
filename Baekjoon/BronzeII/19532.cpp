#include <iostream>
#include <format>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    const int x = (c * e - b * f) / (a * e - b * d);
    const int y = (c * d - a * f) / (b * d - a * e);

    cout << format("{} {}", x, y);
    return 0;
}