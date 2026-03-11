#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int solution(vector<vector<int>> routes)
{
    vector<pair<int, int>> routePV;
    transform(routes.begin(), routes.end(), back_inserter(routePV), [](const auto& r) { return pair(r[1], r[0]); });
    sort(routePV.begin(), routePV.end());
    
    int count = 1, pos = routePV[0].first;
    
    for (int i = 1; i < routePV.size(); i++)
    {
        if (routePV[i].second > pos)
        {
            count++;
            pos = routePV[i].first;
        }
    }
    
    return count;
}