#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    const int side = (1 << n) + 1;
    cout << side * side;
    return 0;
}