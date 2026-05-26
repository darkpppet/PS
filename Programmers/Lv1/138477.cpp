#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    answer.reserve(score.size());
    
    multiset<int> honor;
    
    for (int i = 0; i < min(k, static_cast<int>(score.size())); i++)
    {
        honor.insert(score[i]);
        answer.push_back(*(honor.begin()));
    }
    
    for (int i = k; i < score.size(); i++)
    {
        honor.insert(score[i]);
        honor.erase(honor.begin());
        answer.push_back(*(honor.begin()));
    }
    
    return answer;
}