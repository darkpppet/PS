#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 1;
    
    for (int i : arr)
        answer = lcm(answer ,i);
    
    return answer;
}