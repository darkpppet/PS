#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << lcm(a, b) << '\n';
    }

    return 0;
}