#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

constexpr int kMaxN = 1'000'000;

int main()
{
    bitset<kMaxN> isPrimes;
    isPrimes.flip();

    for (int i = 2; i < sqrt(kMaxN); i++)
    {
        if (!isPrimes.test(i))
            continue;

        for (int j = i * i; j < kMaxN; j += i)
            isPrimes.reset(j);
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        if (n == 4)
        {
            cout << 1 << '\n';
            continue;
        }

        int result = 0;
        for (int a = 3; a <= n / 2; a += 2)
        {
            int b = n - a;

            if (isPrimes.test(a) && isPrimes.test(b))
                result++;
        }

        cout << result << '\n';
    }

    return 0;
}