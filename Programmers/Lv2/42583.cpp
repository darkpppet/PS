#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> truckQueue(deque(truck_weights.begin(), truck_weights.end()));
    queue<pair<int, int>> bridgeQueue({{truckQueue.front(), 1}});
    truckQueue.pop();
    
    int time = 0, tempWeight = bridgeQueue.front().first;
    while (!bridgeQueue.empty())
    {
        time++;
        auto lastTruck = bridgeQueue.front();
        if (time >= lastTruck.second + bridge_length)
        {
            tempWeight -= lastTruck.first;
            bridgeQueue.pop();
        }
        
        if (!truckQueue.empty())
        {
            auto tempTruck = truckQueue.front();
            if (bridgeQueue.size() < bridge_length && tempTruck + tempWeight <= weight)
            {
                tempWeight += tempTruck;

                bridgeQueue.push({tempTruck, time});
                truckQueue.pop();
            }
        }
    }
    
    return time;
}