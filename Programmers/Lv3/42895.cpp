#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(int N, int number)
{
    if (N == number)
        return 1;
    
    array<vector<int>, 9> dp;
    
    dp[1].push_back(N);
    for (int i = 2; i <= 8; i++)
    {
        dp[i].push_back(dp[i - 1][0] * 10 + N);
        if (dp[i][0] == number)
            return i;
        
        for (int ia = 1; ia <= i / 2; ia++)
        {
            int ib = i - ia;
            for (auto a : dp[ia])
            {
                for (auto b : dp[ib])
                {
                    if (b + a == number)
                        return i;
                    dp[i].push_back(b + a);

                    if (b * a == number)
                        return i;
                    dp[i].push_back(b * a);

                    if (a - b == number)
                        return i;
                    dp[i].push_back(a - b);
                    
                    if (b - a == number)
                        return i;
                    dp[i].push_back(b - a);

                    if (a != 0)
                    {
                        if (b / a == number)
                            return i;
                        dp[i].push_back(b / a);
                    }
                    
                    if (b != 0)
                    {
                        if (a / b == number)
                            return i;
                        dp[i].push_back(a / b);
                    }
                }
            }
        }
    }
    return -1;
}