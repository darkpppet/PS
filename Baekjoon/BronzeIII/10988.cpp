#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    auto it = s.begin();
    auto rit = s.rbegin();

    while (it < rit.base())
    {
        if (*it != *rit)
        {
            cout << 0;
            return 0;
        }

        ++it;
        ++rit;
    }

    cout << 1;
    return 0;
}