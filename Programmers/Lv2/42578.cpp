#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> map;
    
    for (const auto& cloth : clothes)
        map[cloth[1]]++;
    
    int answer = 1;
    for (const auto it: map)
        answer *= it.second + 1;
    
    return answer - 1;
}