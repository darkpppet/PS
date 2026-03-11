#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int solution(vector<int> array) {
    unordered_map<int, int> map;
    
    for (int i : array)
    {
        if (map.find(i) == map.end())
        {
            map[i] = 0;
        }
        map[i]++;
    }
    
    bool multi_flag = false;
    int index = -1;
    int max = 0;
    for (pair p : map)
    {
        if (p.second > max)
        {
            multi_flag = false;
            index = p.first;
            max = p.second;
        }
        else if (p.second == max)
        {
            multi_flag = true;
        }
    }
    
    if (multi_flag == true)
    {
        return -1;
    }
    else
    {
        return index;
    }
}