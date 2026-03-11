#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    unordered_set<int> log;
    
    int i = 0;
    for (int a : arr)
    {
        if (auto search = log.find(a); search == log.end())
        {
            answer.push_back(a);
            log.insert(a);
            i++;
        }
        
        if (i == k)
            break;
    }
    
    for (int i = answer.size(); i < k; i++)
    {
        answer.push_back(-1);
    }
    
    return answer;
}