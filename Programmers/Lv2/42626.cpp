#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> sq(scoville.begin(), scoville.end());
    
    while (sq.size() >= 2 && sq.top() < K)
    {
        int first = sq.top();
        sq.pop();
        int second = sq.top();
        sq.pop();
        
        sq.push(first + second * 2);
        answer++;
    }
    
    return sq.top() < K ? -1 : answer;
}