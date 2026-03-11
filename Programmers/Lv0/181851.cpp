#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int, int>> realrank;
    
    for (int i = 0; i < attendance.size(); i++)
    {
        if (attendance[i])
            realrank.push_back(pair(rank[i], i));
    }
    
    sort(realrank.begin(), realrank.end());
    
    answer += realrank[0].second * 10000;
    answer += realrank[1].second * 100;
    answer += realrank[2].second;
    
    return answer;
}