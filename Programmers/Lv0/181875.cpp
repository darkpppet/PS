#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    for (int i = 0; i < strArr.size(); i += 2)
    {
        for (int j = 0; j < strArr[i].size(); j++)
        {
            strArr[i][j] = tolower(strArr[i][j]);
        }
    }

    for (int i = 1; i < strArr.size(); i += 2)
    {
        for (int j = 0; j < strArr[i].size(); j++)
        {
            strArr[i][j] = toupper(strArr[i][j]);
        }
    }

    return strArr;
}