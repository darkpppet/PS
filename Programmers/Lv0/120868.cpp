#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides)
{
    int a = min(sides[0], sides[1]);
    
    return 2 * a - 1;
}