#include <numeric>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2)
{
    if (arr1.size() > arr2.size())
    {
        return 1;
    }
    else if (arr1.size() < arr2.size())
    {
        return -1;
    }
    else
    {
        int sum_arr1 = accumulate(arr1.begin(), arr1.end(), 0);
        int sum_arr2 = accumulate(arr2.begin(), arr2.end(), 0);

        if (sum_arr1 > sum_arr2)
        {
            return 1;
        }
        else if (sum_arr1 < sum_arr2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}