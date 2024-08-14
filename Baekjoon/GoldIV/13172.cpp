#include <iostream>

#define POWER 1000000007

using namespace std;

long long powMod(long long n, long long p)
{
    if (p == 1)
        return n % POWER;

    long long half = powMod(n, p / 2);
    long long origin = (half * half) % POWER;
    if (p % 2 == 0)
        return origin;
    else
        return (origin * n) % POWER;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    long long n[m], s[m];
    for (int i = 0; i < m; i++)
        cin >> n[i] >> s[i];

    long long inversePower = 1000000005;
    long long sum = 0;

    for (int i = 0; i < m; i++)
        sum += (s[i] * powMod(n[i], inversePower)) % POWER;

    cout << sum % POWER;
}