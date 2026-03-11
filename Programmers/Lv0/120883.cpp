#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    for (auto idpwPair : db)
    {
        if (id_pw[0] == idpwPair[0])
        {
            if (id_pw[1] == idpwPair[1])
                return "login";
            else
                return "wrong pw";
        }
    }
    return "fail";
}