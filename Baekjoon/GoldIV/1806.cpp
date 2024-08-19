#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    int sequence[n + 1];
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    sequence[n] = 0;

    int index1 = 0;
    int index2 = 1;

    int sum = sequence[0];
    int minLength = INT_MAX;
    do
    {
        if (sum < s)
        {
            sum += sequence[index2];
            index2++;
        }
        else
        {
            minLength = min(minLength, index2 - index1);
            sum -= sequence[index1];
            index1++;
        }
    } while (index2 <= n && index1 < index2);

    if (minLength == INT_MAX)
        cout << 0;
    else
        cout << minLength;
}