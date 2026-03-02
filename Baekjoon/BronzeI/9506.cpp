#include <iostream>
#include <format>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
            return 0;

        vector<int> divisors;
        int divisorSum = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
                divisorSum += i;
            }
        }

        if (n != divisorSum)
        {
            cout << format("{} is NOT perfect.\n", n);
            continue;
        }

        cout << format("{} = ", n);
        for (int i = 0; i < divisors.size() - 1; i++)
            cout << format("{} + ", divisors[i]);
        cout << divisors.back() << '\n';
    }
}