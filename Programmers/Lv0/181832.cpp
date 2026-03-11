#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    
    int direction = 0;
    
    int rowmin = 0;
    int colmin = 0;
    int rowmax = n - 1;
    int colmax = n - 1;
    
    int row = 0;
    int col = 0;
    
    for (int i = 1; i <= n * n; i++)
    {
        answer[row][col] = i;
        
        switch (direction)
        {
            case 0:
                if (col + 1 > colmax)
                {
                    direction++;
                    rowmin++;
                    row++;
                }
                else
                {
                    col++;
                }
                break;
                
            case 1:
                if (row + 1 > rowmax)
                {
                    direction++;
                    colmax--;
                    col--;
                }
                else
                {
                    row++;
                }
                break;
                
            case 2:
                if (col <= colmin)
                {
                    direction++;
                    rowmax--;
                    row--;
                }
                else
                {
                    col--;
                }
                break;
                
            case 3:
                if (row <= rowmin)
                {
                    direction = 0;
                    colmin++;
                    col++;
                }
                else
                {
                    row--;
                }
                break;
        }
    }
    
    return answer;
}