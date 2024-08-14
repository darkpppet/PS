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

    int space[n + 2][m + 2];

    for (int j = 0; j < m + 2; j++)
    {
        space[0][j] = 2;
        space[n + 1][j] = 2;
    }

    for (int i = 1; i < n + 1; i++)
    {
        space[i][0] = 2;
        space[i][m + 1] = 2;
        for (int j = 1; j < m + 1; j++)
            cin >> space[i][j];
    }

    vector<pair<int, int>> before;
    before.push_back(make_pair(1, 1));
    while (!before.empty())
    {
        vector<pair<int, int>> temp;

        for (pair<int, int> p : before)
        {
            if (space[p.first - 1][p.second] == 0)
            {
                space[p.first - 1][p.second] = 2;
                temp.push_back(make_pair(p.first - 1, p.second));
            }

            if (space[p.first + 1][p.second] == 0)
            {
                space[p.first + 1][p.second] = 2;
                temp.push_back(make_pair(p.first + 1, p.second));
            }

            if (space[p.first][p.second - 1] == 0)
            {
                space[p.first][p.second - 1] = 2;
                temp.push_back(make_pair(p.first, p.second - 1));
            }

            if (space[p.first][p.second + 1] == 0)
            {
                space[p.first][p.second + 1] = 2;
                temp.push_back(make_pair(p.first, p.second + 1));
            }
        }

        before = vector<pair<int, int>>(temp);
    }

    vector<pair<int, int>> innerAir;
    vector<pair<int, int>> cheese;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            switch(space[i][j])
            {
                case 0:
                    innerAir.push_back(make_pair(i, j));
                    break;

                case 1:
                    cheese.push_back(make_pair(i, j));
                    break;
            }
        }
    }

    int time = 0;
    while (!cheese.empty())
    {
        time++;
        vector<pair<int, int>> survivedCheese;
        vector<pair<int, int>> meltedCheeses;

        for (pair<int, int> p : cheese)
        {
            int airCount = 0;
            if (space[p.first - 1][p.second] == 2)
                airCount++;

            if (space[p.first + 1][p.second] == 2)
                airCount++;

            if (space[p.first][p.second - 1] == 2)
                airCount++;

            if (space[p.first][p.second + 1] == 2)
                airCount++;

            if (airCount < 2)
                survivedCheese.push_back(p);
            else
                meltedCheeses.push_back(make_pair(p.first, p.second));
        }

        cheese = vector<pair<int, int>>(survivedCheese);

        vector<pair<int, int>> newAir;
        for (pair<int, int> p : meltedCheeses)
        {
            space[p.first][p.second] = 2;
            if (space[p.first - 1][p.second] == 0)
                newAir.push_back(make_pair(p.first - 1, p.second));

            if (space[p.first + 1][p.second] == 0)
                newAir.push_back(make_pair(p.first + 1, p.second));

            if (space[p.first][p.second - 1] == 0)
                newAir.push_back(make_pair(p.first, p.second - 1));

            if (space[p.first][p.second + 1] == 0)
                newAir.push_back(make_pair(p.first, p.second + 1));
        }

        while (!newAir.empty())
        {
            vector<pair<int, int>> temp;
            for (pair<int, int> p : newAir)
            {
                space[p.first][p.second] = 2;
                if (space[p.first - 1][p.second] == 0)
                    temp.push_back(make_pair(p.first - 1, p.second));

                if (space[p.first + 1][p.second] == 0)
                    temp.push_back(make_pair(p.first + 1, p.second));

                if (space[p.first][p.second - 1] == 0)
                    temp.push_back(make_pair(p.first, p.second - 1));

                if (space[p.first][p.second + 1] == 0)
                    temp.push_back(make_pair(p.first, p.second + 1));
            }

            newAir = vector<pair<int, int>>(temp);
        }
    }

    cout << time;
}