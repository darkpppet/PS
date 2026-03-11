#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Job
{
    Job(int n, int c, int i) : needTime(n), callTime(c), index(i) {};
    
    int needTime;
    int callTime;
    int index;
};

int solution(vector<vector<int>> jobs)
{
    const auto comparer = [](Job a, Job b)
    {
        if (a.needTime == b.needTime)
        {
            if (a.callTime == b.callTime)
            {
                return a.index > b.index;
            }
            else
            {
                return a.callTime > b.callTime;
            }
        }
        else
        {
            return a.needTime > b.needTime;
        }
    };
    
    sort(jobs.begin(), jobs.end());
    
    int time = jobs.front()[0], index = 0;
    long long answer = 0;
    priority_queue<Job, vector<Job>, decltype(comparer)> schedules(comparer);
    
    while (!schedules.empty() || index < jobs.size())
    {
        while (index < jobs.size() && jobs[index][0] <= time)
        {
            schedules.emplace(jobs[index][1], jobs[index][0], index);
            index++;
        }
        
        if (schedules.empty())
        {
            time = jobs[index][0];
            continue;
        }
        
        auto nowJob = schedules.top();
        schedules.pop();
        
        answer += time - nowJob.callTime + nowJob.needTime;
        time += nowJob.needTime;
    }
    
    answer /= jobs.size();
    return answer;
}