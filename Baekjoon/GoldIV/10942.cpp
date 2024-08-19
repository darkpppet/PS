#include <iostream>

using namespace std;

int isPalindrome(int** memo, int* num, int s, int e)
{
    if (memo[s][e] == -1)
    {
        if (num[s] != num[e])
            memo[s][e] = 0;
        else
            memo[s][e] = isPalindrome(memo, num, s + 1, e - 1);
    }

    return memo[s][e];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *num = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    int **memo = new int*[n + 1];
    for (int i = 1; i <= n; i++)
    {
        memo[i] = new int[n + 2];
        memo[i][i] = 1;
        memo[i][i + 1] = num[i] == num[i + 1] ? 1 : 0;
        for (int j = i + 2; j <= n; j++)
            memo[i][j] = -1;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << isPalindrome(memo, num, s, e) << '\n';
    }
}
