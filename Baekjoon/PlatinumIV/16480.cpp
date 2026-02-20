#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long outR, inR;
    cin >> outR >> inR;

    cout << outR * (outR - 2 * inR);

    return 0;
}