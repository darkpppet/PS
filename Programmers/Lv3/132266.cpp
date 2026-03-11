#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

constexpr int INF = 987654321;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<vector<int>> roadsV(n + 1);
    for (auto r : roads)
    {
        roadsV[r[0]].push_back(r[1]);
        roadsV[r[1]].push_back(r[0]);
    }

    vector<int> dist(n + 1, INF);
    dist[destination] = 0;
    {
        queue<pair<int, int>> next;
        next.emplace(destination, 0);
        while (!next.empty())
        {
            auto [node, length] = next.front();
            next.pop();

            for (auto r : roadsV[node])
            {
                if (dist[r] == INF)
                {
                    next.emplace(r, length + 1);
                    dist[r] = length + 1;
                }
            }
        }
    }
    
    vector<int> answer;
    transform(
        sources.begin(),
        sources.end(),
        back_inserter(answer),
        [dist = add_const(dist)](int n) { return dist[n] == INF ? -1 : dist[n]; });
    return answer;
}