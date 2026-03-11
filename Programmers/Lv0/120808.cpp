#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    return gcd(b, r);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int numer = denom2 * numer1 + denom1 * numer2;
    int denom = denom1 * denom2;
    
    int g = gcd(numer, denom);
    
    answer.push_back(numer / g);
    answer.push_back(denom / g);
    
    return answer;
}