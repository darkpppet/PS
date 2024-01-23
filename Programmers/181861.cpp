#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i : arr)
    {
        answer.insert(answer.end(), i, i);
    }

    return answer;
}