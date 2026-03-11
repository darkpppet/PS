#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>

using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    vector<bitset<26>> bitDic;
    
    transform(dic.begin(), dic.end(), back_inserter(bitDic), [](const string& s) 
               {
                   bitset<26> word;
                   for (char c : s)
                       word.set(c - 'a');
                   return word;
               });
    
    bitset<26> bitSpell;
    for (string s: spell)
        bitSpell.set(s[0] - 'a');
    
    for (auto bitWord : bitDic)
    {
        if (bitWord == bitSpell)
            return 1;
    }
    
    return 2;
}