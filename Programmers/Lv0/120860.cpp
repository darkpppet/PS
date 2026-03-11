#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots)
{
    int minX = 256, minY = 256;
    int maxX = -256, maxY = -256;
    
    for (auto dot : dots)
    {
        minX = min(dot[0], minX);
        minY = min(dot[1], minY);
        maxX = max(dot[0], maxX);
        maxY = max(dot[1], maxY);
    }
    
    return (maxX - minX) * (maxY - minY);
}