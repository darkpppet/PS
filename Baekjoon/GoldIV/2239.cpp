#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

using Sudoku = array<array<int, 9>, 9>;
using Position = pair<int, int>;
using DfsPair = pair<Position, int>;

bool check_row(const Sudoku& sudoku, const Position& position)
{
    int row = position.first;
    bitset<10> check;
    for (int j = 0; j < 9; j++)
    {
        auto c = sudoku[row][j];
        if (c == 0)
        {
            continue;
        }
        else if (check[c])
        {
            return false;
        }
        check[c] = true;
    }
    return true;
}

bool check_column(const Sudoku& sudoku, const Position& position)
{
    int column = position.second;
    bitset<10> check;
    for (int i = 0; i < 9; i++)
    {
        auto c = sudoku[i][column];
        if (c == 0)
        {
            continue;
        }
        else if (check[c])
        {
            return false;
        }
        check[c] = true;
    }
    return true;
}

bool check_box(const Sudoku& sudoku, const Position& position)
{
    int row_start = (position.first / 3) * 3;
    int column_start = (position.second / 3) * 3;
    bitset<10> check;

    for (int i = row_start; i < row_start + 3; i++)
    {
        for (int j = column_start; j < column_start + 3; j++)
        {
            auto c = sudoku[i][j];
            if (c == 0)
            {
                continue;
            }
            else if (check[c])
            {
                return false;
            }
            check[c] = true;
        }
    }
    return true;
}

bool check_sudoku(const Sudoku& sudoku, const Position& position)
{
    return check_row(sudoku, position) && check_column(sudoku, position) && check_box(sudoku, position);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Sudoku sudoku {};
    vector<Position> zeroPositions;
    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), sudoku[i].begin(), [](char c) { return c - '0'; });
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                zeroPositions.emplace_back(i, j);
            }
        }
    }

    vector<DfsPair> dfsStack;
    dfsStack.emplace_back(zeroPositions[0], 1);
    sudoku[zeroPositions[0].first][zeroPositions[0].second] = 1;
    int index = 0;

    while (true)
    {
         auto [pos, val] = dfsStack.back();

         if (val > 9)
         {
             sudoku[pos.first][pos.second] = 0;
             dfsStack.pop_back();
             index--;
             dfsStack.back().second++;
             auto [beforePos, beforeVal] = dfsStack.back();
             sudoku[beforePos.first][beforePos.second] = beforeVal;
         }
         else if (check_sudoku(sudoku, pos))
         {
             index++;
             if (index >= zeroPositions.size())
                 break;

             dfsStack.emplace_back(zeroPositions[index], 1);
             sudoku[zeroPositions[index].first][zeroPositions[index].second] = 1;
         }
         else
         {
             dfsStack.back().second++;
             sudoku[pos.first][pos.second] = val + 1;
         }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}