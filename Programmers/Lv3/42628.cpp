#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> operations)
{
    multiset<int> dpq;
    
    for (string operation : operations)
    {
        char opcode = operation[0];
        int operand = stoi(string(operation, 2));
        
        switch (opcode)
        {
            case 'I':
                dpq.insert(operand);
                break;
                
            case 'D':
                if (!dpq.empty())
                {
                    if (operand == 1)
                        dpq.erase(prev(dpq.end()));
                    else
                        dpq.erase(dpq.begin());
                }
                break;
        }
        
    }
    
    if (dpq.empty())
        return vector<int> { 0, 0 };
    else
        return vector<int> { *(dpq.rbegin()), *(dpq.begin()) };
}