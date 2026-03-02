#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    const long long a = a1 * b2 + a2 * b1;
    const long long b = b1 * b2;
    const long long g = gcd(a, b);

    cout << a / g << ' ' << b / g;
    return 0;
}