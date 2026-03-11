#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(vector<vector<int>> board) {
    vector<bitset<100>> danger(board.size());
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 1)
            {
                danger[i].set(j);
                
                if (i - 1 >= 0)
                    danger[i - 1].set(j);
                if (i - 1 >= 0 && j - 1 >= 0)
                    danger[i - 1].set(j - 1);
                if (i - 1 >= 0 && j + 1 < board.size())
                    danger[i - 1].set(j + 1);
                if (j - 1 >= 0)
                    danger[i].set(j - 1);
                if (j + 1 < board.size())
                    danger[i].set(j + 1);
                if (i + 1 < board.size())
                    danger[i + 1].set(j);
                if (i + 1 < board.size() && j - 1 >= 0)
                    danger[i + 1].set(j - 1);
                if (i + 1 < board.size() && j + 1 < board.size())
                    danger[i + 1].set(j + 1);
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (!danger[i][j])
                result++;
        }
    }
    return result;
}