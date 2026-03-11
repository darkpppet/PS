#include <string>
#include <vector>
#include <iostream>

using namespace std;

constexpr int divider = 10007;

int solution(int n, vector<int> tops)
{
    int a = 1, b = 1;

    for (int i = 0; i < n; i++)
    {
        a += tops[i] == 1 ? b * 2 : b;
        b += a;
        
        a %= divider;
        b %= divider;
    }

    return b;
}