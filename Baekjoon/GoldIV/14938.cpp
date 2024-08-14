#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    int items[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> items[i];

    int roads[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            roads[i][j] = INT_MAX / 2;

        roads[i][i] = 0;
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        roads[a][b] = l;
        roads[b][a] = l;
    }

    for(int mid = 1 ; mid <= n; mid++)
        for(int s = 1; s <= n; s++)
            for(int e = 1; e <= n; e++)
                if (roads[s][e] > roads[s][mid] + roads[mid][e])
                    roads[s][e] = roads[s][mid] + roads[mid][e];

    int maxSum = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (roads[i][j] <= m)
                sum += items[j];
        }
        maxSum = max(sum, maxSum);
    }

    cout << maxSum;
}