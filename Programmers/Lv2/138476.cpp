#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    unordered_map<int, int> sizeCounts;
    for (int tangerineSize : tangerine)
        sizeCounts[tangerineSize]++;
    
    vector<int> counts;
    counts.reserve(sizeCounts.size());
    transform(sizeCounts.begin(), sizeCounts.end(), back_inserter(counts), [](auto& k){ return k.second; });
    
    sort(counts.begin(), counts.end(), greater<>());
    
    for (int i = 0; ; i++)
    {
        if (k <= 0)
            return i;
        
        k -= counts[i];
    }
}