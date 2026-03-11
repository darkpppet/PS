#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    int j = 0;
    vector<int> temp;
    for (int i = 0; i < num_list.size(); i++)
    {
        temp.push_back(num_list[i]);
        j++;
        if (j == n)
        {
            answer.push_back(move(temp));
            temp.clear();
            j = 0;
        }
    }
    
    return answer;
}