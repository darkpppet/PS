#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n)
{
    sort(array.begin(), array.end());
    auto pos = lower_bound(array.begin(), array.end(), n);
    
    if (pos == array.end())
    {
        return array.back();
    }
    else if (pos == array.begin())
    {
        return array[0];
    }
    else if (*pos == n)
    {
        return n; 
    }
    else
    {
        int a = *(pos - 1);
        int b = *pos;
        
        return (n - a) <= (b - n) ? a : b;
    }
}