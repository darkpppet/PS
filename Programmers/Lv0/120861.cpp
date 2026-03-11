#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    const int maxX = board[0] / 2;
    const int maxY = board[1] / 2;
    
    vector<int> answer { 0, 0 };
    
    for (string key : keyinput)
    {
        if (key == "up")
            answer[1] = min(maxY, answer[1] + 1);
        else if (key == "down")
            answer[1] = max(-maxY, answer[1] - 1);
        else if (key == "left")
            answer[0] = max(-maxX, answer[0] - 1);
        else
            answer[0] = min(maxX, answer[0] + 1);
    }
    
    return answer;
}