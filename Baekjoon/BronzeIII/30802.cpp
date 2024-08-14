#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int sizes[6];
    cin >> sizes[0] >> sizes[1] >> sizes[2] >> sizes[3] >> sizes[4] >> sizes[5];

    int t, p;
    cin >> t >> p;

    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        int temp = (int)ceil((double)sizes[i] / t);
        sum += temp;
    }

    cout << sum << "\n";
    cout << n / p << ' ' << n % p;
}