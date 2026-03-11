#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int before = -1;
    
    for (int x : arr)
    {
        if (x != before)
        {
            answer.push_back(x);
            before = x;
        }
    }
    
    return answer;
}