#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    answer.reserve(n);
    
    for (int i = 0; i < n; i++)
    {
        int decode = arr1[i] | arr2[i];
        
        string row;
        for (int j = 0; j < n; j++)
        {
            row += decode & 1 ? '#' : ' ';
            decode >>= 1;
        }
        reverse(row.begin(), row.end());
        answer.push_back(row);
    }
    
    return answer;
}