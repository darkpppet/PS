#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int n, num;

    for (int i = 3; i >= 1; i--)
    {
        cin >> s;

        try
        {
            n = stoi(s);
            num = n + i;
            break;
        }
        catch (...)
        {
        }
    }

    if (num % 15 == 0)
    {
        cout << "FizzBuzz";
    }
    else if (num % 3 == 0)
    {
        cout << "Fizz";
    }
    else if (num % 5 == 0)
    {
        cout << "Buzz";
    }
    else
    {
        cout << num;
    }
}