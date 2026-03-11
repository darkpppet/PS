#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string word)
{
    vector<int> wordV;
    for (char c : word)
    {
        int i;
        switch (c)
        {
            case 'A':
                i = 1;
                break;
                
            case 'E':
                i = 2;
                break;
                
            case 'I':
                i = 3;
                break;
                
            case 'O':
                i = 4;
                break;
                
            case 'U':
                i = 5;
                break;
        }
        wordV.push_back(i);
    }
    
    int answer = 0;
    vector<int> temp;
    
    do
    {
        answer++;
        if (temp.size() < 5)
        {
            temp.push_back(1);
        }
        else
        {
            while (temp.back() == 5)
                temp.pop_back();
            temp.back()++;
        }
    } while (temp != wordV);
    
    return answer;
}