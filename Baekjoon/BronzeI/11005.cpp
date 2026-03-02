#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    string result;

    while (n > 0)
    {
        int remainder = n % b;
        if (remainder < 10)
            result += '0' + remainder;
        else
            result += 'A' + remainder - 10;
        n /= b;
    }

    ranges::reverse(result);

    cout << result;
    return 0;
}