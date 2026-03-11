#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer(arr);
    
    int row = arr.size();
    int col = arr[0].size();
    
    if (row == col)
    {
        return arr;
    }
    else if (row > col)
    {
        for (vector<int>& line : answer)
        {
            for (int j = 0; j < row - col; j++)
            {
                line.push_back(0);
            }
        }
    }
    else
    {
        for (int i = 0; i < col - row; i++)
        {
            answer.push_back(vector<int>(col));
        }
    }   
    
    return answer;
}