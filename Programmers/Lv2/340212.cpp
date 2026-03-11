#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    limit -= accumulate(times.begin(), times.end(), 0LL, plus<>());
    
    vector<pair<int, long long>> diffAndFAcc;
    {
        vector<pair<int, int>> diffAndF { { 1, times.front() } };
        for (int i = 1; i < times.size(); i++)
            diffAndF.emplace_back(diffs[i], times[i - 1] + times[i]);
        
        sort(diffAndF.begin(), diffAndF.end(), greater<>());
        
        diffAndFAcc.emplace_back(diffAndF.front());
        for (int i = 1; i < diffAndF.size(); i++)
        {
            if (diffAndF[i].first == diffAndFAcc.back().first)
                diffAndFAcc.back().second += diffAndF[i].second;
            else
                diffAndFAcc.emplace_back(diffAndF[i]);
        }
    }
    
    int level = diffAndFAcc.front().first, i = 0;
    long long factor = 0;
    while (limit >= 0 && level > 1)
    {
        level--;
        
        if (diffAndFAcc[i].first > level)
        {
            factor += diffAndFAcc[i].second;
            i++;
        }
        
        limit -= factor;
    }
    
    return limit >= 0 ? 1 : level + 1;
}