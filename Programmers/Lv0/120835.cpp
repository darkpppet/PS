#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> emergency)
{
    vector<int> temp(emergency);
    unordered_map<int, int> memo;
    
    sort(temp.begin(), temp.end(), greater<int>());
    
    for (int i = 0; i < temp.size(); i++)
        memo[temp[i]] = i + 1;
    
    transform(emergency.begin(), emergency.end(), emergency.begin(), [&memo](int n)
              {
                  return memo[n];
              });
    
    return emergency;
}