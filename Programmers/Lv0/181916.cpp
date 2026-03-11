#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int memo[7] { 0, 0, 0, 0, 0, 0, 0 };
    
    memo[a]++;
    memo[b]++;
    memo[c]++;
    memo[d]++;
    
    int four = 0;
    int three = 0;
    vector<int> two;
    vector<int> one;
    
    for (int i = 1; i <= 6; i++)
    {
        if (memo[i] == 4)
            four = i;
        else if (memo[i] == 3)
            three = i;
        else if (memo[i] == 2)
            two.push_back(i);
        else if (memo[i] == 1)
            one.push_back(i);
    }
    
    if (four != 0)
    {
        return 1111 * four;
    }
    else if (three != 0)
    {
        return (10 * three + one[0]) * (10 * three + one[0]);
    }
    else if (two.size() == 2)
    {
        return (two[0] + two[1]) * abs(two[0] - two[1]);
    }
    else if (two.size() == 1)
    {
        return one[0] * one[1];
    }
    else
    {
        return one[0];
    }
}