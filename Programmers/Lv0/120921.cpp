#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string A, string B)
{  
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    A += A;
    
    auto it = A.find(B);
    
    if (it == string::npos)
    {
        return -1;
    }
    else
    {
        return it;
    }
}