#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    __int128 answer = 1;
    
    for (int i = share + 1; i <= balls; i++)
        answer *= i;
    
    for (int i = 2; i <= balls - share; i++)
        answer /= i;
    
    return static_cast<int>(answer);
}