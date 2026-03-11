#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    string answer = myString;

    for (int i = 0; i < answer.length(); i++)
    {
        answer[i] = toupper(myString[i]);
    }

    return answer;
}