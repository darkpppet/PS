#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> basket(n + 1);
    for (int a = 0; a < m; a++)
    {
        int i, j, k;
        cin >> i >> j >> k;

        for (int b = i; b <= j; b++)
            basket[b] = k;
    }

    for (int i = 1; i <= n; i++)
        cout << basket[i] << ' ';

    return 0;
}