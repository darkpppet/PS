#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> basket(n + 1);
    iota(basket.begin(), basket.end(), 0);

    for (int a = 0; a < m; a++)
    {
        int i, j;
        cin >> i >> j;

        reverse(basket.begin() + i, basket.begin() + j + 1);
    }

    for (int i = 1; i <= n; i++)
        cout << basket[i] << ' ';

    return 0;
}