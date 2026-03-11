#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<int> sumList;
    transform(score.begin(), score.end(), back_inserter(sumList), [](const auto& p)
              {
                  return p[0] + p[1];
              });
    sort(sumList.begin(), sumList.end(), greater<>());
    
    unordered_map<int, int> rankMap;
    for (int i = sumList.size() - 1; i >= 0; i--)
        rankMap[sumList[i]] = i + 1;
    
    vector<int> answer;
    
    for (const auto& p : score)
        answer.push_back(rankMap[p[0] + p[1]]);
    
    return answer;
}