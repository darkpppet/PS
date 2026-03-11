#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer = num_list;
    sort(answer.begin(), answer.end());
    answer = vector<int>(answer.begin()+5, answer.end());

    return answer;
}