#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    string row(n, '*');
    row += '\n';
    for (int i = 0; i < m; i++)
        cout << row;
    
    return 0;
}