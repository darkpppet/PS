using System;

string input = Console.ReadLine();

int n = int.Parse(input.Split(' ')[0]);
int m = int.Parse(input.Split(' ')[1]);

char[,] inputBoard = new char[n, m];

for (int i = 0; i < n; i++)
{
    char[] inputBoardLine = Console.ReadLine().ToCharArray();

    for (int j = 0; j < m; j++)
        inputBoard[i, j] = inputBoardLine[j];
}

char[,] board1 = new char[8, 8] { { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' } };

char[,] board2 = new char[8, 8] { { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
    { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
    { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' } };

int min = 64;

for (int i = 0; i <= n - 8; i++)
{
    for (int j = 0; j <= m - 8; j++)
    {
        int count1 = 0;
        int count2 = 0;

        for (int iIn = 0; iIn < 8; iIn++)
        {
            for (int jIn = 0; jIn < 8; jIn++)
            {
                count1 += board1[iIn, jIn] == inputBoard[i + iIn, j + jIn] ? 0 : 1;
                count2 += board2[iIn, jIn] == inputBoard[i + iIn, j + jIn] ? 0 : 1;
            }
        }

        min = min < count1 ? min : count1;
        min = min < count2 ? min : count2;
    }
}

Console.WriteLine(min);
