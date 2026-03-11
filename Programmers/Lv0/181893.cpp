#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    int s = 0;
    int e = arr.size();
    
    for (int i = 0; i < query.size(); i++)
    {
        if (i % 2 == 0)
        {
            e = s + query[i];
        }
        else
        {
            s += query[i];
        }
    }
    
    vector<int> answer(arr.begin() + s, arr.begin() + e + 1);
    return answer;
}