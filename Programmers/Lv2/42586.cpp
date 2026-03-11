#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    int index = 0;
    int day = 0;
    
    while (index < progresses.size())
    {
        int remain = 100 - (progresses[index] + day * speeds[index]);
        
        day += static_cast<int>(ceil(static_cast<float>(remain) / speeds[index]));
        
        int count = 1;
        index++;
        while (index < progresses.size())
        {
            remain = 100 - (progresses[index] + day * speeds[index]);
            if (remain <= 0)
            {
                count++;
                index++;
            }
            else
            {
                break;
            }
        }
        
        answer.push_back(count);
    }
    
    return answer;
}