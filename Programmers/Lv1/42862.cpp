#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    bitset<32> lostB, reserveB;
    
    for (int l : lost)
        lostB.set(l);
    
    for (int r : reserve)
        reserveB.set(r);
    
    for (int i = 1; i <= 30; i++)
    {
        if (lostB.test(i) && reserveB.test(i))
        {
            lostB.reset(i);
            reserveB.reset(i);
        }
    }
    
    for (int i = 1; i <= 30; i++)
    {
        if (lostB.test(i))
        {
            if (reserveB.test(i - 1))
            {
                reserveB.reset(i - 1);
                lostB.reset(i);
            }
            else if (reserveB.test(i + 1))
            {
                reserveB.reset(i + 1);
                lostB.reset(i);
            }
        }
    }
    
    return n - lostB.count();
}