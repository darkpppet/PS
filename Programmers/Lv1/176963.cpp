#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    unordered_map<string, int> yearningMap;
    
    for (int i = 0; i < name.size(); i++)
        yearningMap.emplace(name[i], yearning[i]);
    
    vector<int> answer;
    answer.reserve(photo.size());
    
    for (int i = 0; i < photo.size(); i++)
    {
        int nostalgia = 0;
        for (const string& who : photo[i])
        {
            unordered_map<string, int>::const_iterator it = yearningMap.find(who);
            nostalgia += (it == yearningMap.cend()) ? 0 : it->second;
        }
        answer.push_back(nostalgia);
    }
    
    return answer;
}