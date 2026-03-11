#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <array>
#include <iostream>

using namespace std;

unordered_set<int> primes;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

void dfs(array<int, 10>& count, int n)
{
    for (int i = 0; i < 10; i++)
    {
        if (count[i] > 0)
        {
            n = n * 10 + i;
            if (primes.find(n) == primes.end() && isPrime(n))
                primes.insert(n);
            
            count[i]--;
            dfs(count, n);
            count[i]++;
            n = (n - i) / 10;
        }
    }
}

int solution(string numbers)
{
    array<int, 10> count {};
    for (char c : numbers)
        count[c - '0']++;
    
    dfs(count, 0);
    
    return primes.size();
}