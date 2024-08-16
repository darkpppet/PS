#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a[n], dictA[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dictA[i] = a[i];
    }

    int m;
    cin >> m;

    int b[m], dictB[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        dictB[i] = b[i];
    }

    sort(dictA, dictA + n, greater<int>());
    sort(dictB, dictB + m, greater<int>());

    vector<int> ans;
    int dictAIndex = 0;
    int dictBIndex = 0;
    int aIndex = 0;
    int bIndex = 0;

    while (aIndex < n && bIndex < m && dictAIndex < n && dictBIndex < m)
    {
        if (dictA[dictAIndex] < dictB[dictBIndex])
        {
            dictBIndex++;
            continue;
        }

        if (dictA[dictAIndex] > dictB[dictBIndex])
        {
            dictAIndex++;
            continue;
        }

        bool isFound = false;
        for (int i = aIndex; i < n; i++)
        {
            if (a[i] == dictA[dictAIndex])
            {
                for (int j = bIndex; j < m; j++)
                {
                    if (b[j] == dictB[dictBIndex])
                    {
                        ans.push_back(a[i]);
                        aIndex = i + 1;
                        bIndex = j + 1;
                        dictAIndex++;
                        dictBIndex++;
                        isFound = true;
                        break;
                    }
                }
            }

            if (isFound)
                break;
        }

        if (!isFound)
        {
            dictAIndex++;
            dictBIndex++;
        }
    }

    cout << ans.size() << '\n';
    for (auto num : ans)
        cout << num << ' ';
}