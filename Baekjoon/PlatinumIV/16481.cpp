#include <iostream>
#include <iomanip>

using namespace std;

constexpr double calcR(double r1, double r2, double r3)
{
    r1 = 1 / r1;
    r2 = 1 / r2;
    r3 = 1 / r3;
    const double r = r1 + r2 + r3;
    return 1 / r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);

    double r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    cout << calcR(r1, r2, r3);

    return 0;
}