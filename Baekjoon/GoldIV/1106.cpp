#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c, n;
    cin >> c >> n;

    unordered_map<int, int> costPeopleMap;

    for (int i = 0; i < n; i++)
    {
        int cost, people;
        cin >> cost >> people;

        if (!costPeopleMap.count(cost))
        {
            costPeopleMap[cost] = people;
        }
        else
        {
            costPeopleMap[cost] = max(costPeopleMap[cost], people);
        }
    }

    vector<int> dp { 0 };
    for (int i = 1; ; i++)
    {
        int temp = 0;

        for (auto k : costPeopleMap)
        {
            if (i - k.first >= 0)
            {
                temp = max(temp, k.second + dp[i - k.first]);
            }
        }

        if (temp >= c)
        {
            cout << i;
            return 0;
        }

        dp.push_back(temp);
    }
}