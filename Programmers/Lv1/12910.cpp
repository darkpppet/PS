#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    for (int n : arr)
    {
        if (n % divisor == 0)
            answer.push_back(n);
    }
    
    if (answer.size() == 0)
        return { -1 };
    
    sort(answer.begin(), answer.end());
    return answer;
}