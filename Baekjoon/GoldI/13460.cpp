#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

using Board = vector<vector<char>>;
using Position = pair<int, int>;

enum class Direction { Left, Right, Up, Down };

pair<Position, Position> moveBeads(const Board& board, Direction direction, Position rPos, Position bPos)
{
    Position rResult, bResult;
    bool isGoal = false;

    switch (direction)
    {
        case Direction::Left:
            for (int j = rPos.second - 1; ; j--)
            {
                int i = rPos.first;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    rResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    rResult = pair(i, j + 1);
                    break;
                }
            }
            for (int j = bPos.second - 1; ; j--)
            {
                int i = bPos.first;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    bResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    bResult = pair(i, j + 1);
                    break;
                }
            }
            if (rResult == bResult && !isGoal)
            {
                if (rPos.second < bPos.second)
                    bResult.second++;
                else
                    rResult.second++;
            }
            break;

        case Direction::Right:
            for (int j = rPos.second + 1; ; j++)
            {
                int i = rPos.first;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    rResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    rResult = pair(i, j - 1);
                    break;
                }
            }
            for (int j = bPos.second + 1; ; j++)
            {
                int i = bPos.first;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    bResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    bResult = pair(i, j - 1);
                    break;
                }
            }
            if (rResult == bResult && !isGoal)
            {
                if (rPos.second < bPos.second)
                    rResult.second--;
                else
                    bResult.second--;
            }
            break;

        case Direction::Up:
            for (int i = rPos.first - 1; ; i--)
            {
                int j = rPos.second;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    rResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    rResult = pair(i + 1, j);
                    break;
                }
            }
            for (int i = bPos.first - 1; ; i--)
            {
                int j = bPos.second;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    bResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    bResult = pair(i + 1, j);
                    break;
                }
            }
            if (rResult == bResult && !isGoal)
            {
                if (rPos.first < bPos.first)
                    bResult.first++;
                else
                    rResult.first++;
            }
            break;

        case Direction::Down:
            for (int i = rPos.first + 1; ; i++)
            {
                int j = rPos.second;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    rResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    rResult = pair(i - 1, j);
                    break;
                }
            }
            for (int i = bPos.first + 1; ; i++)
            {
                int j = bPos.second;
                if (board[i][j] == 'O')
                {
                    isGoal = true;
                    bResult = pair(i, j);
                    break;
                }
                else if (board[i][j] == '#')
                {
                    bResult = pair(i - 1, j);
                    break;
                }
            }
            if (rResult == bResult && !isGoal)
            {
                if (rPos.first < bPos.first)
                    rResult.first--;
                else
                    bResult.first--;
            }
            break;
    }

    return pair { rResult, bResult };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Board board(n, vector<char>(m));
    Position rPos, bPos, goalPos;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        copy(s.begin(), s.end(), board[i].begin());

        for (int j = 0; j < m; j++)
        {
            switch (board[i][j])
            {
                case 'R':
                    board[i][j] = '.';
                    rPos = Position(i, j);
                    break;

                case 'B':
                    board[i][j] = '.';
                    bPos = Position(i, j);
                    break;

                case 'O':
                    goalPos = Position(i, j);
                    break;
            }
        }
    }

    int result = -1;

    queue<tuple<Position, Position, int>> q;
    q.emplace(rPos, bPos, 0);

    while(!q.empty())
    {
        bool isBreak = false;
        auto [tempRPos, tempBPos, depth] = q.front();
        q.pop();

        auto check = [&](Direction direction)
        {
            if (!isBreak)
            {
                auto [rr, rb] = moveBeads(board, direction, tempRPos, tempBPos);
                if (rr == goalPos && rr != rb)
                {
                    result = depth + 1;
                    isBreak = true;
                }
                else if (rb != goalPos && rr != rb && depth < 9)
                {
                    q.emplace(rr, rb, depth + 1);
                }
            }
        };

        check(Direction::Left);
        check(Direction::Right);
        check(Direction::Up);
        check(Direction::Down);

        if (isBreak)
            break;
    }

    cout << result;
}