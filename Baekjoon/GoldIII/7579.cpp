#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int memory[n];
    for (int i = 0; i < n; i++)
        cin >> memory[i];

    int cost[n];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    int memo[n][100 * n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 100 * n; j++)
            memo[i][j] = 0;

    int maxCost = cost[0];
    for (int j = 0; j < maxCost; j++)
        memo[0][j] = 0;
    memo[0][maxCost] = memory[0];

    for (int i = 1; i < n; i++)
    {
        maxCost += cost[i];
        for (int j = 0; j < cost[i]; j++)
            memo[i][j] = memo[i - 1][j];
        for (int j = cost[i]; j <= maxCost; j++)
            memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - cost[i]] + memory[i]);
    }

    for (int i = 0; i <= maxCost; i++)
    {
        if (memo[n - 1][i] >= m)
        {
            cout << i;
            return 0;
        }
    }
}