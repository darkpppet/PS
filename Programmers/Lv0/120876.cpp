#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> lines)
{
    sort(lines.begin(), lines.end(), [](const auto& v1, const auto& v2)
         {
             return v1[0] < v2[0];
         });
    
    priority_queue<int, vector<int>, greater<int>> endQueue;
    
    int answer = 0, linesIndex = 0, linesPointer = lines.front()[0];
    
    while (!endQueue.empty() || linesIndex < lines.size())
    {
        while (linesIndex < lines.size() && lines[linesIndex][0] == linesPointer)
        {
            endQueue.push(lines[linesIndex][1]);
            linesIndex++;
        }
            
        while (!endQueue.empty() && endQueue.top() == linesPointer)
        {
            endQueue.pop();
        }
        
        if (endQueue.size() >= 2)
            answer++;
        
        linesPointer++;
    }
    
    return answer;
}