#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());
    
    int s = 0, e = people.size() - 1;
    
    int answer = 0;
    
    while (s <= e)
    {
        answer++;
        
        int remainLimit = limit - people[e];
        e--;
        
        if (people[s] <= remainLimit)
            s++;
    }
    
    return answer;
}