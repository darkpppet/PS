#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    
    for (vector<int> q : queries)   
    {
        int s = q[0];
        int e = q[1];
        
        reverse(answer.begin() + s, answer.begin() + e + 1);
    }
    
    return answer;
}