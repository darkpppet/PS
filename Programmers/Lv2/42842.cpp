#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int apb = (brown + 4) / 2;
    int ab = (brown + yellow);
    
    int sqrtPart = round(sqrt(apb * apb - 4 * ab));
    
    return { (apb + sqrtPart) / 2, (apb - sqrtPart) / 2 };
}