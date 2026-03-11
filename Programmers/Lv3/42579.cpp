#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, int> total;
    unordered_map<string, pair<pair<int, int>, pair<int, int>>> top2;
    
    for (int i = 0; i < genres.size(); i++)
    {    
        total[genres[i]] += plays[i];
        
        auto nowTop1 = top2[genres[i]].first;
        auto nowTop2 = top2[genres[i]].second;
        if (plays[i] > nowTop1.second)
        {
            top2[genres[i]].second = nowTop1;
            top2[genres[i]].first = pair<int, int>(i, plays[i]);
        }
        else if (plays[i] == nowTop1.second)
        {
            if (plays[i] > nowTop2.second)
            {
                if (i < nowTop1.first)
                {
                    top2[genres[i]].second = nowTop1;
                    top2[genres[i]].first = pair<int, int>(i, plays[i]);
                }
                else
                {
                    top2[genres[i]].second = pair<int, int>(i, plays[i]);
                }
            }
            else if (plays[i] == nowTop2.second && i < nowTop2.first)
            {
                top2[genres[i]].second = pair<int, int>(i, plays[i]);
            }
        }
        else if (plays[i] > nowTop2.second || (plays[i] == nowTop2.second && i < nowTop2.first))
        {
            top2[genres[i]].second = pair<int, int>(i, plays[i]);
        }
    }
    
    vector<pair<string, int>> totalVec(total.begin(), total.end());
    sort(totalVec.begin(), totalVec.end(), [](const auto a, const auto b)
         {
             return a.second > b.second;
         });
    
    vector<int> answer;
    
    for (auto p : totalVec)
    {
        answer.push_back(top2[p.first].first.first);
        if (top2[p.first].second.second > 0)
            answer.push_back(top2[p.first].second.first);
    }
    
    return answer;
}