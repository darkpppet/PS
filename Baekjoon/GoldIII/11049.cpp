#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int r[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> r[i] >> c[i];

    int memo[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        memo[i][i] = 0;
        memo[i][i + 1] = r[i] * c[i] * c[i + 1];
    }
    memo[n - 1][n - 1] = 0;

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int tempMin = INT_MAX;

            for (int k = j; k < j + i; k++)
            {
                int temp = memo[j][k] + memo[k + 1][j + i] + r[j] * c[k] * c[j + i];
                tempMin = min(temp, tempMin);
            }
            memo[j][j + i] = tempMin;
        }
    }

    cout << memo[0][n - 1];
}