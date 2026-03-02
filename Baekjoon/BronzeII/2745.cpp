#include <iostream>

using namespace std;

int main()
{
    string n;
    int b;
    cin >> n >> b;

    int result = 0;

    for (const char digitChar : n)
    {
        int digit;
        if (isdigit(digitChar))
            digit = digitChar - '0';
        else
            digit = digitChar - 'A' + 10;

        result *= b;
        result += digit;
    }

    cout << result;
    return 0;
}