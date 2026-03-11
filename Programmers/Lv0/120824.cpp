#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int e = 0;
    int o = 0;
    
    for (int num : num_list)
    {
        if (num % 2 == 0)
            e++;
        else
            o++;
    }
    
    return vector { e, o };
}