#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int room[n][n];

    long long verticalMemo[n][n];
    long long horizontalMemo[n][n];
    long long diagonalMemo[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> room[i][j];

    bool isBlocked = false;
    for (int i = 0; i < n; i++)
    {
        if (room[0][i] == 0 && isBlocked == false)
        {
            horizontalMemo[0][i] = 1;
        }
        else
        {
            horizontalMemo[0][i] = 0;
            isBlocked = true;
        }
        horizontalMemo[i][0] = 0;
        verticalMemo[0][i] = 0;
        verticalMemo[i][0] = 0;
        diagonalMemo[0][i] = 0;
        diagonalMemo[i][0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (room[i][j] == 0 && room[i - 1][j] == 0 && room[i][j - 1] == 0)
            {
                diagonalMemo[i][j] = horizontalMemo[i - 1][j - 1] + verticalMemo[i - 1][j - 1] + diagonalMemo[i - 1][j - 1];
            }
            else
            {
                diagonalMemo[i][j] = 0;
            }

            if (room[i][j] == 0)
            {
                horizontalMemo[i][j] = horizontalMemo[i][j - 1] + diagonalMemo[i][j - 1];
                verticalMemo[i][j] = verticalMemo[i - 1][j] + diagonalMemo[i - 1][j];
            }
            else
            {
                horizontalMemo[i][j] = 0;
                verticalMemo[i][j] = 0;
            }
        }
    }

    cout << horizontalMemo[n - 1][n - 1] + verticalMemo[n - 1][n - 1] + diagonalMemo[n - 1][n - 1];
}