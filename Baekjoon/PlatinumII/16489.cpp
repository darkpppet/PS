#include <iostream>
#include <iomanip>
#include <cmath>
#include <format>

using namespace std;

constexpr double calcSs(const double a, const double b, const double c)
{
    const double s = (a + b + c) / 2;
    return s * (s - a) * (s - b) * (s - c);
}

constexpr double calcOutRs(const double a, const double b, const double c, const double ss)
{
    return (a * a * b * b * c * c) / (16 * ss);
}

constexpr double calcInRs(const double a, const double b, const double c, const double ss)
{
    return (4 * ss) / ((a + b + c) * (a + b + c));
}

constexpr double calcD(const double outRs, const double inRs)
{
    return sqrt(outRs - 2 * sqrt(outRs * inRs));
}

constexpr double calcK(const double outRs, const double inRs)
{
    return sqrt(outRs) + sqrt(inRs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);

    double a, b, c;
    cin >> a >> b >> c;

    const double ss = calcSs(a, b, c);
    const double outRs = calcOutRs(a, b, c, ss);
    const double inRs = calcInRs(a, b, c, ss);
    const double d = calcD(outRs, inRs);
    const double k = calcK(outRs, inRs);

    cout << format("{}\n{}\n{}\n{}\n{}", sqrt(ss), sqrt(outRs), sqrt(inRs), d, k);

    return 0;
}