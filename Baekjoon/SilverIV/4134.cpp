#include <iostream>
#include <cmath>

using namespace std;

template<integral T>
bool isPrime(T n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        if (n <= 2)
        {
            cout << 2 << '\n';
            continue;
        }

        if (n % 2 == 0)
            n++;

        while (!isPrime(n))
            n += 2;

        cout << n << '\n';
    }

    return 0;
}