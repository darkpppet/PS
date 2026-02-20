#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <optional>
#include <ranges>
#include <algorithm>
#include <cmath>

using namespace std;

class Prime
{
private:
    constexpr static long long powMod(__int128 a, long long b, const long long y)
    {
        if (a == 0)
            return 0;
        if (a == 1)
            return 1;

        if (b == 0)
            return 1;
        if (b == 1)
            return static_cast<long long>(a % y);

        if (y == 1)
            return 0;

        __int128 z = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
                z = (a * z) % y;
            a = (a * a) % y;
            b >>= 1;
        }
        return static_cast<long long>(z);
    }

    constexpr static pair<long long, long long> findDAndS(long long nMinus1)
    {
        long long s = 0;
        while (nMinus1 % 2 == 0)
        {
            nMinus1 /= 2;
            s++;
        }
        const long long d = nMinus1;

        return {d, s};
    }

    constexpr static bool checkIsPrimeWithA(const long long n, const long long d, const long long s, const long long a)
    {
        long long aPowerD = powMod(a, d, n);
        if (aPowerD == 1 || aPowerD == n - 1)
            return true;

        for (int i = 0; i < s - 1; i++)
        {
            aPowerD = static_cast<long long>((static_cast<__int128>(aPowerD) * aPowerD) % n);
            if (aPowerD == n - 1)
                return true;
        }

        return false;
    }

public:
    static bool checkIsPrime(const long long n)
    {
        constexpr array aArr {2LL, 3LL, 5LL, 7LL, 11LL, 13LL, 17LL, 19LL, 23LL, 29LL, 31LL, 37LL};

        if (n <= 1)
            return false;
        if (n == 2)
            return true;

        auto [d, s] = findDAndS(n - 1);
        for (const long long i : aArr)
        {
            if (n <= i)
                break;

            if (!checkIsPrimeWithA(n, d, s, i))
                return false;
        }

        return true;
    }
};

class Factorization
{
private:
    constexpr static long long g(const __int128 x, const long long n, const __int128 c = 1)
    {
        return static_cast<long long>((((x * x) % n) + c + n) % n);
    }

    constexpr static optional<long long> rho(const long long n, const long long x0 = 2, const long long c = 1)
    {
        long long x = x0;
        long long y = x0;
        long long d = 1;

        while (d == 1)
        {
            x = g(x, n, c);
            y = g(g(y, n, c), n, c);
            d = gcd(x - y, n);
        }

        if (d == n)
        {
            if (c == 1)
                return rho(n, x0, -1);
            if (c == -1)
                return rho(n, x0, 2);
            if (x0 < 20)
                return rho(n, x0 + 1, 1);

            return nullopt;
        }

        return d;
    }

    static void factorize_internal(const long long n, vector<long long> &primeFactors)
    {
        if (n <= 1)
            return;

        if (Prime::checkIsPrime(n))
        {
            primeFactors.push_back(n);
            return;
        }

        const auto optA = rho(n);
        if (!optA.has_value())
            return;

        const long long a = optA.value();
        const long long b = n / a;

        factorize_internal(a, primeFactors);
        factorize_internal(b, primeFactors);
    }

public:
    static void factorize(long long n, vector<long long>& primeFactors)
    {
        while (n % 2 == 0)
        {
            primeFactors.push_back(2);
            n /= 2;
        }
        factorize_internal(n, primeFactors);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> primeFactors;
    Factorization::factorize(n, primeFactors);

    ranges::sort(primeFactors);

    for (const long long primeFactor: primeFactors)
        cout << primeFactor << '\n';

    return 0;
}
