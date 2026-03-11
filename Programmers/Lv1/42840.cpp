#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    const vector<int> cycle1 { 1, 2, 3, 4, 5 };
    const vector<int> cycle2 { 2, 1, 2, 3, 2, 4, 2, 5 };
    const vector<int> cycle3 { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int point1 = 0, point2 = 0, point3 = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        int i1 = i % cycle1.size();
        int i2 = i % cycle2.size();
        int i3 = i % cycle3.size();
        
        point1 += answers[i] == cycle1[i1] ? 1 : 0;
        point2 += answers[i] == cycle2[i2] ? 1 : 0;
        point3 += answers[i] == cycle3[i3] ? 1 : 0;
    }
    
    int highscore = max(max(point1, point2), point3);
    vector<int> answer;
    if (point1 == highscore)
        answer.push_back(1);
    if (point2 == highscore)
        answer.push_back(2);
    if (point3 == highscore)
        answer.push_back(3);
    return answer;
}