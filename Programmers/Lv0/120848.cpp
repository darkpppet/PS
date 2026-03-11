#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int i = 1;
    int temp = 1;
    while (true)
    {
        temp *= i + 1;
        if (temp > n)
            return i;
        i++;
    }
}