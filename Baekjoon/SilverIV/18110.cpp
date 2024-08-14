#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int cut = (int)round(n * 0.15);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int sum = 0;
    for (int i = cut; i < n - cut; i++)
    {
        sum += arr[i];
    }

    int result = (int)round((double)sum / (n - 2 * cut));

    cout << result;
}