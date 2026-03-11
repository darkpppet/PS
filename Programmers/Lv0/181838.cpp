#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2)
{
    int merged_date1 = date1[0] * 10000 + date1[1] * 100 + date1[2];
    int merged_date2 = date2[0] * 10000 + date2[1] * 100 + date2[2];

    return merged_date1 < merged_date2 ? 1 : 0;
}