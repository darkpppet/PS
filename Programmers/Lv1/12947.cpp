#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    int sum = 0, tempx = x;
    while (tempx > 0)
    {
        sum += tempx % 10;
        tempx /= 10;
    }
    
    return x % sum == 0;
}