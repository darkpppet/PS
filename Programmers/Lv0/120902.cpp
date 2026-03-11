#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    my_string += ' ';
    int answer = 0;
    
    string temp;
    bool isPlus = true;
    bool isNum = true;
    
    for (char c : my_string)
    {
        switch (c)
        {
            case ' ':
                if (isNum)
                {
                    int num = stoi(temp, nullptr);
                    num *= isPlus ? 1 : -1;
                    answer += num;
                    temp.clear();
                }
                break;
                
            case '+':
                isNum = false;
                isPlus = true;
                break;
                
            case '-':
                isNum = false;
                isPlus = false;
                break;
                
            default:
                temp += c;
                isNum = true;
                break;
        }
    }
    
    return answer;
}