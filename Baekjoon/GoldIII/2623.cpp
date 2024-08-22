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

    vector<int> shorter[n + 1];
    int bigCount[n + 1];
    for (int i = 1; i <= n; i++)
        bigCount[i] = 0;

    for (int i = 0; i < m; i++)
    {
        int tempN;
        cin >> tempN;

        int before;
        cin >> before;
        for (int j = 1; j < tempN; j++)
        {
            int now;
            cin >> now;
            shorter[before].push_back(now);
            bigCount[now]++;
            before = now;
        }
    }

    vector<int> before;
    for (int i = 1; i <= n; i++)
        if (bigCount[i] == 0)
            before.push_back(i);

    vector<int> result;
    while (!before.empty())
    {
        vector<int> temp;
        for (auto p : before)
        {
            result.push_back(p);
            for (auto s : shorter[p])
            {
                bigCount[s]--;
                if (bigCount[s] == 0)
                    temp.push_back(s);
            }
        }
        before = vector<int>(temp);
    }

    if (result.size() < n)
    {
        cout << 0;
        return 0;
    }

    for (auto p : result)
        cout << p << '\n';
}