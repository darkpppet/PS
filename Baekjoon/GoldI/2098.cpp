#include <iostream>
#include <vector>
#include <climits>
#include <bitset>

using namespace std;

int tsp(int last, int mask, int n, int** w, int** memo)
{
    if (mask == (1 << n) - 1)
        return w[last][0] == 0 ? INT_MAX / 2 : w[last][0];

    if (memo[last][mask] != -1)
        return memo[last][mask];

    memo[last][mask] = INT_MAX / 2;
    for (int i = 0; i < n; i++)
    {
        if (mask & 1 << i || w[last][i] == 0)
            continue;
        memo[last][mask] = min(memo[last][mask], tsp(i, mask | 1 << i, n, w, memo) + w[last][i]);
    }

    return memo[last][mask];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int **w = new int*[n];
    for (int i = 0; i < n; i++)
    {
        w[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    int **memo = new int*[n];
    for (int i = 0; i < n; i++)
    {
        memo[i] = new int[1 << n];
        for (int j = 0; j < 1 << n; j++)
            memo[i][j] = -1;
    }

    cout << tsp(0, 1, n, w, memo);
}
