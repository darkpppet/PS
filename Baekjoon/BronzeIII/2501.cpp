#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;

        if (count < k)
        {
            count++;
            continue;
        }

        cout << i;
        return 0;
    }

    cout << 0;
    return 0;
}