#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (string line : picture)
    {
        string newline = "";
        
        for (char pixel : line)
        {
            newline.append(k, pixel);
        }
        
        for (int i = 0; i < k; i++)
            answer.push_back(newline);
    }
    
    return answer;
}