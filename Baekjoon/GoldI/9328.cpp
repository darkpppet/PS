#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

using Position = pair<size_t, size_t>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++)
    {
        int h, w;
        cin >> h >> w;
        vector<vector<char>> building(h, vector<char>(w));
        vector<bitset<100>> checker(h);
        auto checkSet = [&checker](int i, int j) { checker[i].set(j); };
        auto checkTest = [&checker](int i, int j) { return checker[i].test(j); };

        for (int i = 0; i < h; i++)
        {
            string s;
            cin >> s;
            copy(s.begin(), s.end(), building[i].begin());
        }

        bitset<26> keys;
        {
            string s;
            cin >> s;
            if (s != "0")
            {
                for (char c : s)
                {
                    keys.set(c - 'a');
                }
            }
        }

        array<vector<Position>, 26> lockedDoors {};

        queue<Position> before;
        int result = 0;
        auto init = [&](int i, int j)
        {
            auto c = building[i][j];
            if (c == '.')
            {
                checkSet(i, j);
                before.emplace(i, j);
            }
            else if (c >= 'a' && c <= 'z')
            {
                checkSet(i, j);
                keys.set(c - 'a');
                before.emplace(i, j);
            }
            else if (c >= 'A' && c <= 'Z')
            {
                lockedDoors[c - 'A'].emplace_back(i, j);
            }
            else if (c == '$')
            {
                result++;
                checkSet(i, j);
                before.emplace(i, j);
            }
        };

        for (int i = 0; i < h; i++)
        {
            init(i, 0);
            init(i, w - 1);
        }
        for (int j = 1; j < w - 1; j++)
        {
            init(0, j);
            init(h - 1, j);
        }

        for (int a = 0; a < 26; a++)
        {
            if (keys.test(a))
            {
                for (auto [i, j]: lockedDoors[a])
                {
                    before.emplace(i, j);
                }
                lockedDoors[a].clear();
            }
        }

        auto next = [&](auto i, auto j)
        {
            if (i >= 0 && i < h && j >= 0 && j < w && !checkTest(i, j))
            {
                auto c = building[i][j];
                if (c == '.')
                {
                    checkSet(i, j);
                    before.emplace(i, j);
                }
                else if (c >= 'a' && c <= 'z')
                {
                    checkSet(i, j);
                    keys.set(c - 'a');
                    before.emplace(i, j);
                    for (auto [il, jl]: lockedDoors[c - 'a'])
                    {
                        checkSet(il, jl);
                        before.emplace(il, jl);
                    }
                    lockedDoors[c - 'a'].clear();
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    if (keys.test(c - 'A'))
                    {
                        checkSet(i, j);
                        before.emplace(i, j);
                    }
                    else
                    {
                        lockedDoors[c - 'A'].emplace_back(i, j);
                    }
                }
                else if (c == '$')
                {
                    result++;
                    checkSet(i, j);
                    before.emplace(i, j);
                }
            }
        };

        while (!before.empty())
        {
            auto [i, j] = before.front();
            before.pop();

            next(i - 1, j);
            next(i + 1, j);
            next(i, j - 1);
            next(i, j + 1);
        }

        cout << result << '\n';
    }
}