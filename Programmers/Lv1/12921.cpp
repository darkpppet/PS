#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<bool> isNotPrime(n + 1);
    
    int answer = 0;
    
    for (int i = 2; i <= n; i++)
    {
        if (isNotPrime[i] == false)
            answer++;
        
        for (int j = i + i; j <= n; j += i)
            isNotPrime[j] = true;
    }
    
    return answer;
}