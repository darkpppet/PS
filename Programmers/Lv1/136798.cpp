#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int number, int limit, int power)
{
    vector<int> divCounts(number + 1);
    for (int i = 1; i <= number; i++)
    {
        for (int j = i; j <= number; j += i)
            divCounts[j]++;
    }
    
    transform(divCounts.begin(),
             divCounts.end(),
             divCounts.begin(),
             [limit, power](int count)
             {
                 return count > limit ? power : count;
             });
    
    return accumulate(divCounts.begin(), divCounts.end(), 0);
}