#include <iostream>

using namespace std;

constexpr long long combination(int n, int r)
{
    if (r == n)
        return 1;

    if (r > n / 2)
        r = n - r;

    long long result = 1;
    for (int i = 1; i <= r; i++)
    {
        result *= n - i + 1;
        result /= i;
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        cout << combination(m, n) << '\n';
    }

    return 0;
}