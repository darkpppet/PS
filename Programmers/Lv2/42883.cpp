#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    vector<char> numList { '9' + 1 };
    
    int counter = 0, pointer = 0;
    while (counter < k && pointer < number.size())
    {
        if (numList.back() < number[pointer])
        {
            numList.pop_back();
            counter++;
            continue;
        }
        
        numList.push_back(number[pointer]);
        pointer++;
    }

    if (counter == k)
    {
        for (int i = pointer; i < number.size(); i++)
            numList.push_back(number[i]);
    }
    else
    {
        while (counter < k)
        {
            numList.pop_back();
            counter++;
        }
    }
    
    return string(next(numList.begin()), numList.end());
}