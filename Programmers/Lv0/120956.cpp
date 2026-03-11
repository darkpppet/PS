#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string s : babbling)
    {
        auto pos = s.find("aya");
        if (pos != string::npos)
        {
            s.replace(pos, 3, "0");
        }
        
        pos = s.find("ye");
        if (pos != string::npos)
        {
            s.replace(pos, 2, "0");
        }
        
        pos = s.find("woo");
        if (pos != string::npos)
        {
            s.replace(pos, 3, "0");
        }
        
        pos = s.find("ma");
        if (pos != string::npos)
        {
            s.replace(pos, 2, "0");
        }
        
        while (true)
        {
            pos = s.find("0");
            if (pos == string::npos)
                break;
        
            s.replace(pos, 1, "");
        }
        
        if (s == "")
            answer++;
    }
    
    return answer;
}