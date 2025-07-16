#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
using BoardRow = vector<int>;
using Board = vector<BoardRow>;

int n;

using DfsPair = pair<Board, int>;

enum class Direction
{
    Left,
    Right,
    Up,
    Down,
};

Board swipeBoard(const Board& board, Direction direction)
{
    Board result(n, BoardRow(n));

    switch (direction)
    {
        case Direction::Left:
            for (int i = 0; i < n; i++)
            {
                int newIndex = 0;
                int tempSum = 0;
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] > 0)
                    {
                        if (tempSum == 0)
                        {
                            tempSum = board[i][j];
                        }
                        else if (tempSum == board[i][j])
                        {
                            tempSum += board[i][j];
                            result[i][newIndex] = tempSum;
                            tempSum = 0;
                            newIndex++;
                        }
                        else
                        {
                            result[i][newIndex] = tempSum;
                            tempSum = board[i][j];
                            newIndex++;
                        }
                    }
                }
                if (tempSum > 0)
                {
                    result[i][newIndex] = tempSum;
                }
            }
            break;

        case Direction::Right:
            for (int i = 0; i < n; i++)
            {
                int newIndex = n - 1;
                int tempSum = 0;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (board[i][j] > 0)
                    {
                        if (tempSum == 0)
                        {
                            tempSum = board[i][j];
                        }
                        else if (tempSum == board[i][j])
                        {
                            tempSum += board[i][j];
                            result[i][newIndex] = tempSum;
                            tempSum = 0;
                            newIndex--;
                        }
                        else
                        {
                            result[i][newIndex] = tempSum;
                            tempSum = board[i][j];
                            newIndex--;
                        }
                    }
                }
                if (tempSum > 0)
                {
                    result[i][newIndex] = tempSum;
                }
            }
            break;

        case Direction::Up:
            for (int j = 0; j < n; j++)
            {
                int newIndex = 0;
                int tempSum = 0;
                for (int i = 0; i < n; i++)
                {
                    if (board[i][j] > 0)
                    {
                        if (tempSum == 0)
                        {
                            tempSum = board[i][j];
                        }
                        else if (tempSum == board[i][j])
                        {
                            tempSum += board[i][j];
                            result[newIndex][j] = tempSum;
                            tempSum = 0;
                            newIndex++;
                        }
                        else
                        {
                            result[newIndex][j] = tempSum;
                            tempSum = board[i][j];
                            newIndex++;
                        }
                    }
                }
                if (tempSum > 0)
                {
                    result[newIndex][j] = tempSum;
                }
            }
            break;

        case Direction::Down:
            for (int j = 0; j < n; j++)
            {
                int newIndex = n - 1;
                int tempSum = 0;
                for (int i = n - 1; i >= 0; i--)
                {
                    if (board[i][j] > 0)
                    {
                        if (tempSum == 0)
                        {
                            tempSum = board[i][j];
                        }
                        else if (tempSum == board[i][j])
                        {
                            tempSum += board[i][j];
                            result[newIndex][j] = tempSum;
                            tempSum = 0;
                            newIndex--;
                        }
                        else
                        {
                            result[newIndex][j] = tempSum;
                            tempSum = board[i][j];
                            newIndex--;
                        }
                    }
                }
                if (tempSum > 0)
                {
                    result[newIndex][j] = tempSum;
                }
            }
            break;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    Board board(n, BoardRow(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int result = -1;
    queue<DfsPair> dfsQueue;
    dfsQueue.emplace(std::move(board), 0);

    while (!dfsQueue.empty())
    {
        const auto& [tempBoard, depth] = dfsQueue.front();

        if (depth >= 5)
        {
            for (const auto& row : tempBoard)
            {
                result = max(result, *max_element(row.begin(), row.end()));
            }
        }
        else
        {
            dfsQueue.emplace(swipeBoard(tempBoard, Direction::Left), depth + 1);
            dfsQueue.emplace(swipeBoard(tempBoard, Direction::Right), depth + 1);
            dfsQueue.emplace(swipeBoard(tempBoard, Direction::Up), depth + 1);
            dfsQueue.emplace(swipeBoard(tempBoard, Direction::Down), depth + 1);
        }

        dfsQueue.pop();
    }

    cout << result;
}