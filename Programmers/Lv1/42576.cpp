#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> nameCount;
    
    for (string name : participant)
        nameCount[name]++;
    
    for (string name : completion)
    {
        nameCount[name]--;
        if (nameCount[name] == 0)
            nameCount.erase(nameCount.find(name));
    }
    
    return (*nameCount.begin()).first;
}