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
            char temp;
            cin >> temp;

            switch (temp)
            {
                case 'O':
                    map[i][j] = 1;
                    break;

                case 'X':
                    map[i][j] = 0;
                    break;

                case 'I':
                    map[i][j] = 2;
                    startI = i;
                    startJ = j;
                    break;

                case 'P':
                    map[i][j] = 3;
                    break;
            }
        }
    }

    int check[n + 2][m + 2];

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            check[i][j] = map[i][j] == 0 ? 0 : -1;
        }
    }

    vector<pair<int, int>> before;
    before.push_back(make_pair(startI, startJ));
    check[startI][startJ] = 0;
    int count = 0;
    while (!before.empty())
    {
        vector<pair<int, int>> temp;
        for (pair<int, int> p : before)
        {
            if (check[p.first - 1][p.second] == -1)
            {
                switch (map[p.first - 1][p.second])
                {
                    case 3:
                        count++;

                    case 1:
                        check[p.first - 1][p.second] = 0;
                        temp.push_back(make_pair(p.first - 1, p.second));
                        break;
                }
            }

            if (check[p.first + 1][p.second] == -1)
            {
                switch (map[p.first + 1][p.second])
                {
                    case 3:
                        count++;

                    case 1:
                        check[p.first + 1][p.second] = 0;
                        temp.push_back(make_pair(p.first + 1, p.second));
                        break;
                }
            }

            if (check[p.first][p.second - 1] == -1)
            {
                switch (map[p.first][p.second - 1])
                {
                    case 3:
                        count++;

                    case 1:
                        check[p.first][p.second - 1] = 0;
                        temp.push_back(make_pair(p.first, p.second - 1));
                        break;
                }
            }

            if (check[p.first][p.second + 1] == -1)
            {
                switch (map[p.first][p.second + 1])
                {
                    case 3:
                        count++;

                    case 1:
                        check[p.first][p.second + 1] = 0;
                        temp.push_back(make_pair(p.first, p.second + 1));
                        break;
                }
            }
        }

        before = vector<pair<int, int>>(temp);
    }

    if (count == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << count;
    }
}