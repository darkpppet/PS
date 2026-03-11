#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    vector<int> adders { 0 };
    
    int base = 5;
    int now = 0;
    while (now <= r)
    {
        vector<int> tempadders(adders);
        for (int a : tempadders)
        {
            now = base + a;
            adders.push_back(now);
            if (now >= l && now <= r)
            {
                answer.push_back(now);
            }
            else if (now > r)
            {
                break;
            }
        }
        base *= 10;
    }
    
    if (answer.empty())
        answer.push_back(-1);
    
    return answer;
}