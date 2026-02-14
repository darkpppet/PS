#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sum = 0;
    bool needTriple = false;

    for (int i = 0; i < 13; i++)
    {
        const char c = static_cast<char>(cin.get());

        if (c == '*')
        {
            if (i % 2 == 1)
                needTriple = true;

            continue;
        }

        int n = c - '0';
        if (i % 2 == 1)
            n *= 3;

        sum += n;
    }

    int x = 10 - (sum % 10);

    if (needTriple)
        x = (x * 7) % 10;

    cout << x;

    return 0;
}