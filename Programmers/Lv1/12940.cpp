#include <numeric>
#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
    int g = gcd(n, m);
    int l = n * m / g;

    return { g, l };
}