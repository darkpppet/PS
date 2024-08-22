#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int memo[n + 1][10][0b10000000000];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < 0b10000000000; k++)
                memo[i][j][k] = 0;

    for (int i = 1; i <= 9; i++)
        memo[1][i][1 << i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int b = 0; b < 0b10000000000; b++)
        {
            memo[i][0][0b0000000001 | b] += memo[i - 1][1][b];
            memo[i][0][0b0000000001 | b] %= 1000000000;
            for (int d = 1; d <= 8; d++)
            {
                memo[i][d][1 << d | b] += memo[i - 1][d - 1][b] + memo[i - 1][d + 1][b];
                memo[i][d][1 << d | b] %= 1000000000;
            }
            memo[i][9][0b1000000000 | b] += memo[i - 1][8][b];
            memo[i][9][0b1000000000 | b] %= 1000000000;
        }
    }

    int result = 0;

    for (int d = 0; d <= 9; d++)
    {
        result += memo[n][d][0b1111111111];
        result %= 1000000000;
    }

    cout << result;
}