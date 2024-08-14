#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int map[n + 2][m + 2];

    for (int j = 0; j < m + 2; j++)
    {
        map[0][j] = 0;
        map[n + 1][j] = 0;
    }

    int startI, startJ;
    for (int i = 1; i <= n; i++)
    {
        map[i][0] = 0;
        map[i][m + 1] = 0;
        for (int j = 1; j <= m; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 2)
            {
                startI = i;
                startJ = j;
            }

            map[i][j] = temp;
        }
    }

    int result[n + 2][m + 2];

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            result[i][j] = map[i][j] == 0 ? 0 : -1;
        }
    }

    vector<pair<int, int>> before;
    before.push_back(make_pair(startI, startJ));
    result[startI][startJ] = 0;
    int distance = 0;
    while (!before.empty())
    {
        vector<pair<int, int>> temp;
        distance++;
        for (pair<int, int> p : before)
        {
            if (map[p.first - 1][p.second] == 0 && result[p.first - 1][p.second] == -1)
            {
                result[p.first - 1][p.second] = 0;
            }
            else if (map[p.first - 1][p.second] == 1 && result[p.first - 1][p.second] == -1)
            {
                result[p.first - 1][p.second] = distance;
                temp.push_back(make_pair(p.first - 1, p.second));
            }

            if (map[p.first + 1][p.second] == 0 && result[p.first + 1][p.second] == -1)
            {
                result[p.first + 1][p.second] = 0;
            }
            else if (map[p.first + 1][p.second] == 1 && result[p.first + 1][p.second] == -1)
            {
                result[p.first + 1][p.second] = distance;
                temp.push_back(make_pair(p.first + 1, p.second));
            }

            if (map[p.first][p.second - 1] == 0 && result[p.first][p.second - 1] == -1)
            {
                result[p.first][p.second - 1] = 0;
            }
            else if (map[p.first][p.second - 1] == 1 && result[p.first][p.second - 1] == -1)
            {
                result[p.first][p.second - 1] = distance;
                temp.push_back(make_pair(p.first, p.second - 1));
            }

            if (map[p.first][p.second + 1] == 0 && result[p.first][p.second + 1] == -1)
            {
                result[p.first][p.second + 1] = 0;
            }
            else if (map[p.first][p.second + 1] == 1 && result[p.first][p.second + 1] == -1)
            {
                result[p.first][p.second + 1] = distance;
                temp.push_back(make_pair(p.first, p.second + 1));
            }
        }

        before = vector<pair<int, int>>(temp);
    }

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < m + 1; j++)
      {
          cout << result[i][j] << ' ';
      }
      cout << '\n';
    }
}