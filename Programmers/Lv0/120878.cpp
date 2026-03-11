#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int i = 2;
    
    while (a >= i)
    {
        if (a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
        else
        {
            i++;
        }
    }
    
    while (true)
    {
        if (b % 2 == 0)
            b /= 2;
        else if (b % 5 == 0)
            b /= 5;
        else
            return b == 1 ? 1 : 2;
    }
}