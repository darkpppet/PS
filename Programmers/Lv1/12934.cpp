#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long trysqrt = static_cast<long long>(sqrt(static_cast<long double>(n)));
    
    if (n == trysqrt * trysqrt)
        return (trysqrt + 1) * (trysqrt + 1);
    
    return -1;
}