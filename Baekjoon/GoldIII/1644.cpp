#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

constexpr int kMaxPrime = 3'999'971;

void generatePrimes(int n, vector<int>& primes)
{
    bitset<kMaxPrime + 1> check;
    check.set(2);
    n = min(n, kMaxPrime);

    for (int i = 3; i <= n; i += 2)
    {
        if (check.test(i))
            continue;

        primes.push_back(i);
        for (int j = i; j <= n; j += i)
            check.set(j);
    }
}

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    if (n == 2)
    {
        cout << 1;
        return 0;
    }

    vector<int> primes { 2 };
    generatePrimes(n, primes);

    int count = 0;
    int sum = 0;
    int left = 0, right = 0;

    while (right < primes.size())
    {
        sum += primes[right];

        while (sum > n && left <= right)
        {
            sum -= primes[left];
            left++;
        }

        if (sum == n)
            count++;

        right++;
    }

    cout << count;
    return 0;
}