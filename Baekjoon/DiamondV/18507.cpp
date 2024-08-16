#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double n, m;
    cin >> n >> m;

    long double count = 0;

    if ((int)n % 2 == 0)
    {
        long double maxP = floor(pow(m / n, 1 / (n - 1)));
        long double maxQ = floor(pow(m / (n - 1), 1 / n));

        count += 2 * min(maxP, maxQ) + 1;
    }
    else
    {
        count += 2 * m * m + 3 * m + 1; //(2m+1)(m+1) = 2m^2 + 3m + 1 //0<=p<=m(m+1): all q(2m+1)

        for (long double p = -1; p >= -m; p--)
        {
            long double v = -p / n;
            long double point = (n - 1) * v * pow(v, 1 / (n - 1)); //극값: (n-1) * (-p/n)^(n/n-1) = (n-1) * (-p/n) * (-p/n)^(n-1)

            double tempCount = 2 * (m - floor(point)); //극대 위 절반, 극소 밑 절반

            if (tempCount > 0)
            {
                count += tempCount;
            }
            else
            {
                break;
            }
        }
    }

    cout << (long long)count;
}