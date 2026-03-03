#include <iostream>

using namespace std;

constexpr long long kPrime = 10'007;

constexpr long long powMod(long long a, long long b, const long long y)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;

    if (b == 0)
        return 1;
    if (b == 1)
        return a % y;

    if (y == 1)
        return 0;

    long long z = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            z = (a * z) % y;
        a = (a * a) % y;
        b >>= 1;
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long nFactorial = 1, kFactorial = 1, nMinusKFactorial = 1;
    {
        long long factorial = 1;
        for (long long i = 2; i <= n; i++)
        {
            factorial *= i;
            factorial %= kPrime;
            if (i == k)
                kFactorial = factorial;
            if (i == n - k)
                nMinusKFactorial = factorial;
            if (i == n)
                nFactorial = factorial;
        }
    }

    const long long inversed = powMod((kFactorial * nMinusKFactorial) % kPrime, kPrime - 2, kPrime);

    cout << (nFactorial * inversed) % kPrime;

    return 0;
}