#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz)
{
    vector<string> answer;
    
    for (auto oneQuiz : quiz)
    {
        string temp;
        int num1, num2, sum;
        bool isPlus = true;
        
        auto it = oneQuiz.begin();
        while (*it != ' ')
        {
            temp += *it;
            it++;
        }
        num1 = stoi(temp);
        it++;
        
        if (*it == '-')
            isPlus = false;
        it += 2;
        
        temp.clear();
        while (*it != ' ')
        {
            temp += *it;
            it++;
        }
        num2 = stoi(temp);
        num2 *= isPlus ? 1 : -1;
        
        it += 3;
        
        temp.clear();
        while (it != oneQuiz.end())
        {
            temp += *it;
            it++;
        }
        sum = stoi(temp);
        
        answer.push_back(sum == num1 + num2 ? "O" : "X");
    }
    
    return answer;
}