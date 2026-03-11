#include <string>
#include <array>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    array<int, 26> memo;
    fill(memo.begin(), memo.end(), -1);
    vector<int> answer;
    answer.reserve(s.size());
    
    for (int i = 0; i < s.size(); i++)
    {
        int index = memo[s[i] - 'a'];
        answer.push_back(index == -1 ? -1 : i - index);
        memo[s[i] - 'a'] = i;
    }
    
    return answer;
}