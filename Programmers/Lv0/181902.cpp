#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    constexpr int asciiA = 65;
    constexpr int asciiZ = 90;
    constexpr int asciia = 97;
    constexpr int asciiz = 122;
    
    
    for (char c : my_string)
    {
        if (c >= asciiA && c <= asciiZ)
        {
            answer[c - asciiA]++;
        }
        else
        {
            answer[c - asciia + 26]++;
        }
    }
    
    return answer;
}