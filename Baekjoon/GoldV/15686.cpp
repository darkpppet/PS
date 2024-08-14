#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> chickens;
    vector<pair<int, int>> houses;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;

            switch (temp)
            {
                case 1:
                    houses.push_back(make_pair(i, j));
                    break;

                case 2:
                    chickens.push_back(make_pair(i, j));
                    break;
            }
        }
    }

    vector<int> chickenIndex;
    for (int i = 0; i < chickens.size(); i++)
        chickenIndex.push_back(i);

    vector<bool> forCombination;
    for (int i = m; i < chickens.size(); i++)
        forCombination.push_back(false);
    for (int i = 0; i < m; i++)
        forCombination.push_back(true);

    int minLength = INT_MAX;

    do
    {
        vector<pair<int, int>> nowChicken;
        for (int i = 0; i < forCombination.size(); i++)
            if (forCombination[i])
                nowChicken.push_back(chickens[chickenIndex[i]]);

        int length = 0;
        for (auto h: houses)
        {
            int tempLength = INT_MAX;
            for (auto c : nowChicken)
            {
                int temp = abs(h.first - c.first) + abs(h.second - c.second);
                tempLength = min(temp, tempLength);
            }

            length += tempLength;
        }
        minLength = min(length, minLength);
    } while (next_permutation(forCombination.begin(), forCombination.end()));

    cout << minLength;
}