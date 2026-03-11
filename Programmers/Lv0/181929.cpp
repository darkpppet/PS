#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;

    int p = 1;
    int s = 0;

    for (int i : num_list)
    {
        p *= i;
        s += i;
    }

    answer = p < s * s ? 1 : 0;

    return answer;
}