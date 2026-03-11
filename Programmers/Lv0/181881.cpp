#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    while (true)
    {
        vector<int> before(arr);
        
        bool is_same = true;
        
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= 50 && arr[i] % 2 == 0)
            {
                arr[i] /= 2;
                is_same = false;
            }
            else if (arr[i] < 50 && arr[i] % 2 != 0)
            {
                arr[i] *= 2;
                arr[i]++;
                is_same = false;
            }
        }
        
        if (is_same)
            break;
        else
            answer++;
    }
    
    return answer;
}