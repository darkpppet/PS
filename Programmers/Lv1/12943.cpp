#include <iostream>

using namespace std;

int solution(int num)
{
    long long tempnum = static_cast<long long>(num);
    for (int i = 0; i < 500; i++)
    {
        if (tempnum == 1)
            return i;
        
        if (tempnum % 2 == 0)
            tempnum /= 2;
        else
            tempnum = tempnum * 3 + 1;
    }
    
    return -1;
}