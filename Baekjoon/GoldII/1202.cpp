#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    pair<int, int> j[n];
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        j[i] = make_pair(m, v);
    }

    int c[k];
    for (int i = 0; i < k; i++)
        cin >> c[i];

    sort(j, j + n);
    sort(c, c + k);
    priority_queue<int> pq;

    long long sumV = 0;
    int index = 0;
    for (auto nowC : c)
    {
        while (index < n)
        {
            if (j[index].first > nowC)
                break;

            pq.push(j[index].second);
            index++;
        }

        if (!pq.empty())
        {
            sumV += pq.top();
            pq.pop();
        }
    }

    cout << sumV;
}