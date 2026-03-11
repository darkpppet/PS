#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2)
{
    int num1 = stoi(bin1, nullptr, 2);
    int num2 = stoi(bin2, nullptr, 2);
    
    int sum = num1 + num2;
    
    if (sum == 0)
        return "0";
    
    string answer = bitset<11>(sum).to_string();
    answer = answer.substr(answer.find('1'));
    
    return answer;
}