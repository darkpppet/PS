#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int liquids[n];
    for (int i = 0; i < n; i++)
        cin >> liquids[i];

    pair<int, int> index = make_pair(0, n - 1);
    pair<int, int> ans = index;
    int minValue = abs(liquids[index.first] + liquids[index.second]);

    while (index.first < index.second)
    {
        int tempValue = liquids[index.first] + liquids[index.second];

        if (abs(tempValue) < minValue)
        {
            ans = make_pair(index.first, index.second);
            minValue = abs(tempValue);
        }

        if (tempValue < 0)
        {
            index.first++;
        }
        else if (tempValue > 0)
        {
            index.second--;
        }
        else
        {
            break;
        }
    }

    cout << liquids[ans.first] << ' ' << liquids[ans.second];
}