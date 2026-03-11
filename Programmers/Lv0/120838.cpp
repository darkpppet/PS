#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string letter) {
    const vector<string> mos {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string answer = "";
    string temp = "";
    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] == ' ')
        {
            auto it = find(mos.begin(), mos.end(), temp);
            answer += distance(mos.begin(), it) + 'a';
            temp = "";
        }
        else
        {
            temp += letter[i];
        }
    }
    
    auto it = find(mos.begin(), mos.end(), temp);
    answer += distance(mos.begin(), it) + 'a';
    
    return answer;
}