#include <string>
#include <vector>

using namespace std;

void customSort(vector<int>& vec)
{
    if (vec[0] <= vec[1])
        return;
    
    swap(vec[0], vec[1]);
}

bool canInsert(vector<int>& wallet, vector<int>& bill)
{
    return bill[0] <= wallet[0] && bill[1] <= wallet[1];
}

int solution(vector<int> wallet, vector<int> bill)
{
    customSort(wallet);
    customSort(bill);
    
    int answer = 0;
    while (!canInsert(wallet, bill))
    {
        bill[1] /= 2;
        customSort(bill);
        
        ++answer;
    }
 
    return answer;
}