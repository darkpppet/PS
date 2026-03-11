#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer = num_list;

    int last = answer.back();
    int last_before = *(answer.end() - 2);

    if (last > last_before)
    {
        answer.push_back(last - last_before);
    }
    else
    {
        answer.push_back(2 * last);
    }

    return answer;
}