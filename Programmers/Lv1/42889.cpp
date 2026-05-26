#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> lastCount(N + 2);
    for (int last : stages)
        lastCount[last]++;
    
    vector<pair<float, int>> failRates;
    failRates.reserve(N);
    
    int totalChallengers = lastCount[N + 1];
    
    for (int i = N; i >= 1; i--)
    {
        totalChallengers += lastCount[i];
        float nowFailer = lastCount[i];
        
        float failRate = totalChallengers == 0 ? 0 : nowFailer / totalChallengers;
        
        failRates.emplace_back(failRate, i);
    }
    
    sort(failRates.begin(), failRates.end(), [](auto k1, auto k2)
         {
             if (k1.first == k2.first)
                 return k1.second < k2.second;
             
             return k1.first > k2.first;
         });
    
    vector<int> answer;
    answer.reserve(N);
    
    for (auto [_, index] : failRates)
        answer.push_back(index);
    
    return answer;
}