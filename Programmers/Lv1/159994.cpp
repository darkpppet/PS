#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    vector<string>::const_iterator it1 = cards1.cbegin();
    vector<string>::const_iterator it2 = cards2.cbegin();
    
    for (const string& word : goal)
    {
        if (it1 < cards1.cend() && *it1 == word)
        {
            ++it1;
            continue;
        }
        
        if (it2 < cards2.cend() && *it2 == word)
        {
            ++it2;
            continue;
        }
        
        return "No";
    }
    
    return "Yes";
}