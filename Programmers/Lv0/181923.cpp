#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (vector<int> q : queries)
    {
        int s = q[0];
        int e = q[1];
        int k = q[2];
        
        int a = 1000001;
        for (int i = s; i <= e; i++)
        {
            if (arr[i] > k && arr[i] < a)
            {
                a = arr[i];
            }
        }
        
        answer.push_back(a == 1000001 ? -1 : a);
    }
    
    return answer;
}