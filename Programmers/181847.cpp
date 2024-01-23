#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string n_str)
{
    int i = 0;
    for (; i < n_str.size() && n_str[i] == '0'; i++) {};

    return n_str.substr(i);
}

int main()
{
    cout << solution("854020");
}