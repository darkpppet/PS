#include <string>
#include <vector>
#include <tuple>

using namespace std;
using index4 = tuple<int, int, int, int>;

int solution(vector<vector<int>> dots)
{
    const vector<index4> lp
    {
        index4(0, 1, 2, 3), index4(0, 2, 1, 3), index4(0, 3, 1, 2)
    };
    
    for (int i = 0; i < lp.size(); i++)
    {
        auto p1 = dots[get<0>(lp[i])];
        auto p2 = dots[get<1>(lp[i])];
        auto p3 = dots[get<2>(lp[i])];
        auto p4 = dots[get<3>(lp[i])];
        
        if ((p2[1] - p1[1]) * (p4[0] - p3[0]) == (p2[0] - p1[0]) * (p4[1] - p3[1]))
            return 1;
    }
    
    return 0;
}