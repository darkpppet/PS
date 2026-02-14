#include <iostream>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(3);

    while (true)
    {
        int p0, q0, r0;
        cin >> p0 >> q0 >> r0;
        if (p0 == 0 && q0 == 0 && r0 == 0)
            return 0;

        if (r0 == 0)
        {
            cout << 2 * numbers::pi * (p0 - q0) << '\n';
            continue;
        }

        if (r0 == q0)
        {
            cout << q0 / gcd(p0, q0) * 8 * (p0 - q0) << '\n';
            continue;
        }

        const double p = static_cast<double>(p0);
        const double q = static_cast<double>(q0);
        const double r = static_cast<double>(r0);

        const double t = q / gcd(p0, q0);
        const double ellint = comp_ellint_2(2 * sqrt(q * r) / (q + r));
        const double coef = 4 * (p - q) * (q + r) / q;

        cout << t * coef * ellint << '\n';
    }
}