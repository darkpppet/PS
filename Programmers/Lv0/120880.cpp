#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n)
{
    sort(numlist.begin(), numlist.end(), [n](const int a, const int b)
         {
             const int newa = abs(a - n);
             const int newb = abs(b - n);
             
             if (newa == newb)
                 return a > b;
             else
                 return newa < newb;
         });
    
    return numlist;
}