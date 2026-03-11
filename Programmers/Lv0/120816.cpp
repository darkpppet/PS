#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int slice, int n) {
    return ceil((double)n / slice);
}