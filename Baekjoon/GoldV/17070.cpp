#include <iostream>
#include <vector>

using namespace std;

bool isHorizontal(pair<pair<int, int>, pair<int, int>> pipe)
{
    if (pipe.first.first == pipe.second.first && pipe.first.second + 1 == pipe.second.second)
        return true;
    else
        return false;
}

bool isVertical(pair<pair<int, int>, pair<int, int>> pipe)
{
    if (pipe.first.first + 1 == pipe.second.first && pipe.first.second == pipe.second.second)
        return true;
    else
        return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int room[n + 2][n + 2];

    for (int j = 0; j < n + 2; j++)
    {
        room[0][j] = 1;
        room[n + 1][j] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        room[i][0] = 1;
        room[i][n + 1] = 1;
        for (int j = 1; j <= n; j++)
        {
            cin >> room[i][j];
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> before;
    before.push_back(make_pair(make_pair(1, 1), make_pair(1, 2)));

    int count = 0;
    while (!before.empty())
    {
        vector<pair<pair<int, int>, pair<int, int>>> temp;

        for (auto pipe: before)
        {
            if (pipe.second.first == n && pipe.second.second == n)
            {
                count++;
                continue;
            }
            else if (isHorizontal(pipe))
            {
                if (room[pipe.second.first][pipe.second.second + 1] == 0)
                {
                    temp.push_back(make_pair(make_pair(pipe.first.first, pipe.first.second + 1), make_pair(pipe.second.first, pipe.second.second + 1)));

                    if (room[pipe.second.first + 1][pipe.second.second] == 0 && room[pipe.second.first + 1][pipe.second.second + 1] == 0)
                        temp.push_back(make_pair(make_pair(pipe.first.first, pipe.first.second + 1), make_pair(pipe.second.first + 1, pipe.second.second + 1)));
                }
            }
            else if (isVertical(pipe))
            {
                if (room[pipe.second.first + 1][pipe.second.second] == 0)
                {
                    temp.push_back(make_pair(make_pair(pipe.first.first + 1, pipe.first.second), make_pair(pipe.second.first + 1, pipe.second.second)));

                    if (room[pipe.second.first][pipe.second.second + 1] == 0 && room[pipe.second.first + 1][pipe.second.second + 1] == 0)
                        temp.push_back(make_pair(make_pair(pipe.first.first + 1, pipe.first.second), make_pair(pipe.second.first + 1, pipe.second.second + 1)));
                }
            }
            else
            {
                if (room[pipe.second.first + 1][pipe.second.second] == 0)
                    temp.push_back(make_pair(make_pair(pipe.first.first + 1, pipe.first.second + 1), make_pair(pipe.second.first + 1, pipe.second.second)));

                if (room[pipe.second.first][pipe.second.second + 1] == 0)
                    temp.push_back(make_pair(make_pair(pipe.first.first + 1, pipe.first.second + 1), make_pair(pipe.second.first, pipe.second.second + 1)));

                if (room[pipe.second.first + 1][pipe.second.second] == 0
                && room[pipe.second.first][pipe.second.second + 1] == 0
                && room[pipe.second.first + 1][pipe.second.second + 1] == 0)
                    temp.push_back(make_pair(make_pair(pipe.first.first + 1, pipe.first.second + 1), make_pair(pipe.second.first + 1, pipe.second.second + 1)));
            }
        }

        before = vector<pair<pair<int, int>, pair<int, int>>>(temp);
    }

    cout << count;
}