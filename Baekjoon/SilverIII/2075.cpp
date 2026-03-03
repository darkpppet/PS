#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<tuple<int, int, int>> pq;

    vector<vector<int>> table(n);
    for (int i = 0; i < n; i++)
        table[i].reserve(n);

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            table[i].push_back(num);
        }
    }

    for (int i = 0; i < n; i++)
        pq.emplace(table[i].back(), i, n - 1);

    for (int k = 1; k < n; k++)
    {
        auto [num, i, j] = pq.top();
        pq.pop();
        if (j - 1 >= 0)
            pq.emplace(table[i][j - 1], i, j - 1);
    }

    cout << get<0>(pq.top());

    return 0;
}
