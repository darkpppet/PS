#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int before2 = 0, before1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int now = (before2 + before1) % 1234567;
        before2 = before1;
        before1 = now;
    }
    
    return before1;
}