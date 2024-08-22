#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;

        int wonder[n + 1];
        int check[n + 1];

        for (int i = 1; i <= n; i++)
        {
            cin >> wonder[i];
            check[i] = 0;
        }

        int result = 0;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (check[i])
                continue;

            int before = i;
            int nowCount = count;
            while (!check[before])
            {
                count++;
                check[before] = count;
                before = wonder[before];
            }

            if (check[before] > nowCount)
                result += check[before] - nowCount - 1;
            else
                result += count - nowCount;
        }

        cout << result << '\n';
    }
}
