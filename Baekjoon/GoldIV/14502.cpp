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

    int room[n + 2][m + 2];

    for (int j = 0; j < m + 2; j++)
    {
        room[0][j] = 1;
        room[n + 1][j] = 1;
    }

    vector<pair<int, int>> space;
    vector<pair<int, int>> virus;

    for (int i = 1; i < n + 1; i++)
    {
        room[i][0] = 1;
        room[i][m + 1] = 1;
        for (int j = 1; j < m + 1; j++)
        {
            int temp;
            cin >> temp;
            switch (temp)
            {
                case 0:
                    space.push_back(make_pair(i, j));
                    break;

                case 2:
                    virus.push_back(make_pair(i, j));
                    break;
            }
            room[i][j] = temp;
        }
    }

    int maxCount = 0;
    for (int i = 0; i < space.size(); i++)
    {
        for (int j = i + 1; j < space.size(); j++)
        {
            for (int k = j + 1; k < space.size(); k++)
            {
                int newRoom[n + 2][m + 2];
                for (int a = 0; a < n + 2; a++)
                {
                    for (int b = 0; b < m + 2; b++)
                        newRoom[a][b] = room[a][b];
                }

                newRoom[space[i].first][space[i].second] = 1;
                newRoom[space[j].first][space[j].second] = 1;
                newRoom[space[k].first][space[k].second] = 1;

                vector<pair<int, int>> newVirus = vector<pair<int, int>>(virus);
                while (!newVirus.empty())
                {
                    vector<pair<int, int>> temp;
                    for (auto p : newVirus)
                    {
                        if (newRoom[p.first - 1][p.second] == 0)
                        {
                            newRoom[p.first - 1][p.second] = 2;
                            temp.push_back(make_pair(p.first - 1, p.second));
                        }
                        if (newRoom[p.first + 1][p.second] == 0)
                        {
                            newRoom[p.first + 1][p.second] = 2;
                            temp.push_back(make_pair(p.first + 1, p.second));
                        }
                        if (newRoom[p.first][p.second - 1] == 0)
                        {
                            newRoom[p.first][p.second - 1] = 2;
                            temp.push_back(make_pair(p.first, p.second - 1));
                        }
                        if (newRoom[p.first][p.second + 1] == 0)
                        {
                            newRoom[p.first][p.second + 1] = 2;
                            temp.push_back(make_pair(p.first, p.second + 1));
                        }
                    }
                    newVirus = vector<pair<int, int>>(temp);
                }

                int count = 0;
                for (int a = 0; a < n + 2; a++)
                {
                    for (int b = 0; b < m + 2; b++)
                    {
                        if (newRoom[a][b] == 0)
                            count++;
                    }
                }
                maxCount = max(count, maxCount);
            }
        }
    }

    cout << maxCount;
}