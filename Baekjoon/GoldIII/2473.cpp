#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long liquids[n];
    for (int i = 0; i < n; i++)
        cin >> liquids[i];

    sort(liquids, liquids + n);

    long long minValue = LLONG_MAX;
    long long ans[3];
    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        long long tempValueBase = liquids[i];

        while (left < right)
        {
            long long tempValue = tempValueBase + liquids[left] + liquids[right];

            if (abs(tempValue) < minValue)
            {
                ans[0] = liquids[i];
                ans[1] = liquids[left];
                ans[2] = liquids[right];
                minValue = abs(tempValue);
            }

            if (tempValue < 0)
                left++;
            else if (tempValue > 0)
                right--;
            else
                break;
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}