#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    
    vector<int> before { triangle[0][0] };
    for (int i = 1; i < triangle.size(); i++)
    {
        const auto& row = triangle[i];
        vector<int> now;
        now.reserve(row.size());
        
        now.push_back(before.front() + row.front());
        for (int j = 1; j < row.size() - 1; j++)
        {
            int bigger = max(before[j - 1], before[j]);
            now.push_back(row[j] + bigger);
        }
        now.push_back(before.back() + row.back());
        
        before = move(now);
    }
    
    return *max_element(before.begin(), before.end());
}