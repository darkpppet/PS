#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int longSide = 0, shortSide = 0;
    
    for (auto size : sizes)
    {
        if (size[0] > size[1])
            swap(size[0], size[1]);
        
        longSide = max(longSide, size[1]);
        shortSide = max(shortSide, size[0]);
    }
    
    return longSide * shortSide;
}