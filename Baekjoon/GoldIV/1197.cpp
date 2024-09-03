#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<pair<int, pair<int, int>>> vertices;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vertices.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(vertices.begin(), vertices.end());

    int mother[v + 1];
    for (int i = 1; i <= v; i++)
        mother[i] = i;

    int ans = 0;
    int memberCount = 0;
    for (auto p : vertices)
    {
        int v1 = p.second.first;
        int v2 = p.second.second;

        int rootV1 = mother[v1];
        int rankV1 = 0;
        while (rootV1 != mother[rootV1])
        {
            rootV1 = mother[rootV1];
            rankV1++;
        }

        int tempRootV1 = mother[v1];
        while (rootV1 != mother[tempRootV1])
        {
            int temp = mother[tempRootV1];
            mother[tempRootV1] = rootV1;
            tempRootV1 = temp;
        }

        int rootV2= mother[v2];
        int rankV2 = 0;
        while (rootV2 != mother[rootV2])
        {
            rootV2 = mother[rootV2];
            rankV2++;
        }

        int tempRootV2 = mother[v2];
        while (rootV2 != mother[tempRootV2])
        {
            int temp = mother[tempRootV2];
            mother[tempRootV2] = rootV2;
            tempRootV2 = temp;
        }

        if (rootV1 != rootV2)
        {
            ans += p.first;
            memberCount++;

            if (rankV1 < rankV2)
                mother[rootV1] = rootV2;
            else
                mother[rootV2] = rootV1;
        }

        if (memberCount >= v)
            break;
    }

    cout << ans;
}