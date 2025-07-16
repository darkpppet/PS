#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> ds(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> ds[i];

        vector<vector<int>> pre(n + 1);
        vector<vector<int>> post(n + 1);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;

            post[x].push_back(y);
            pre[y].push_back(x);
        }

        int w;
        cin >> w;

        unordered_set<int> need { w };
        vector<int> first;

        queue<int> temp;
        temp.push(w);

        while (!temp.empty())
        {
            int now = temp.front();
            temp.pop();

            if (pre[now].empty())
            {
                first.push_back(now);
                continue;
            }

            for (int p : pre[now])
            {
                if (!need.count(p))
                {
                    need.insert(p);
                    temp.push(p);
                }
            }
        }

        int time = 0;
        bitset<1001> check;
        vector<pair<int, int>> before;
        int minBefore = numeric_limits<int>::max();

        for (int f : first)
        {
            if (need.count(f))
            {
                need.erase(f);
                before.emplace_back(ds[f], f);
                minBefore = min(minBefore, ds[f]);
            }
        }

        while (!before.empty())
        {
            vector<pair<int, int>> tempBefore;
            int tempMinBefore = numeric_limits<int>::max();

            time += minBefore;

            for (auto [buildTime, building]: before)
            {
                if (buildTime - minBefore <= 0)
                {
                    check[building] = true;
                    for (auto tPost: post[building])
                    {
                        if (need.count(tPost))
                        {
                            bool canBuild = true;
                            for (auto tPre: pre[tPost])
                            {
                                if (!check[tPre])
                                {
                                    canBuild = false;
                                    break;
                                }
                            }
                            if (canBuild)
                            {
                                need.erase(tPost);
                                tempBefore.emplace_back(ds[tPost], tPost);
                                tempMinBefore = min(tempMinBefore, ds[tPost]);
                            }
                        }
                    }
                }
                else
                {
                    tempBefore.emplace_back(buildTime - minBefore, building);
                    tempMinBefore = min(tempMinBefore, buildTime - minBefore);
                }
            }

            before = std::move(tempBefore);
            minBefore = tempMinBefore;
        }

        cout << time << '\n';
    }
}