#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common)
{
    bool isD = true;
    int d = common[1] - common[0];
    
    for (int i = 0; i < common.size() - 1; i++)
    {
        if (common[i] + d != common[i + 1])
        {
            isD = false;
            break;
        }
    }
    
    if (isD)
        return common.back() + d;
    else
        return common.back() * common[1] / common[0];
}