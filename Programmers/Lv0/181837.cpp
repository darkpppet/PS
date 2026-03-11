#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order)
{
    int cost = 0;
    for (string s : order)
    {
        if (s == "iceamericano" || s == "americanoice" || s == "hotamericano" || s == "americanohot" || s == "americano" || s == "anything")
        {
            cost += 4500;
        }
        else
        {
            cost += 5000;
        }
    }
    return cost;
}