#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    
    for (auto command : commands)
    {
        int i = command[0], j = command[1], k = command[2];
        
        vector<int> subArr(array.begin() + i - 1, array.begin() + j);
        nth_element(subArr.begin(), subArr.begin() + k - 1, subArr.end());
        //sort(subArr.begin(), subArr.end());
        answer.push_back(subArr[k - 1]);
    }
    
    return answer;
}