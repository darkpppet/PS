#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr)
{
    int answer = 0;

    unordered_map<int, int> count_map;

    for (string s : strArr)
    {
        count_map.insert({s.size(), 0});
        count_map[s.size()]++;
    }

    return (max_element(count_map.begin(), count_map.end(), [](auto p1, auto p2)
    {
        return p1.second < p2.second;
    }))->second;
}

int main()
{
    cout << solution({"a","bc","d","efg","hi"});
}