#include <vector>
#include <bitset>

using namespace std;

constexpr int maxSum = 1000 + 999 + 998;

int solution(vector<int> nums)
{
    bitset<maxSum + 1> isNotPrime;
    
    for (int i = 2; i <= maxSum; i++)
    {
        for (int j = i + i; j <= maxSum; j += i)
            isNotPrime.set(j);
    }
    
    int answer = 0;
    for (int i1 = 0; i1 < nums.size() - 2; i1++)
    {
        for (int i2 = i1 + 1; i2 < nums.size() - 1; i2++)
        {
            for (int i3 = i2 + 1; i3 < nums.size(); i3++)
            {
                if (!isNotPrime[(nums[i1] + nums[i2] + nums[i3])])
                    answer++;
            }
        }
    }
    
    return answer;
}