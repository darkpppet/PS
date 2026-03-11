#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int r = floor(sqrt(n));
    if (r * r == n)
        return 1;
    else
        return 2;
}