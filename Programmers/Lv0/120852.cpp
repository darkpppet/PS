#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    const vector<int> primes
    {
        2, 3, 5, 7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };
    
    vector<int> answer;
    
    for (int p: primes)
    {
        if (p > n)
            break;
        
        if (n % p == 0)
        {
            answer.push_back(p);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1)
        answer.push_back(n);
    
    return answer;
}