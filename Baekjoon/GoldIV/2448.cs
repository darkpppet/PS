using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

Dictionary<int, int[,]> memo = new()
{
    [3] = new int[,]
    {
        { 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 1, 1, 1, 1, 1 }
    }
};

int[,] MakePattern(int n)
{
    if (!memo.ContainsKey(n))
    {
        int[,] subPattern = MakePattern(n / 2);

        int[,] pattern = new int[n, 2 * n - 1];

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                pattern[i, j + n / 2] = subPattern[i, j];
                pattern[i + n / 2, j] = subPattern[i, j];
                pattern[i + n / 2, j + n] = subPattern[i, j];
            }
        }

        memo[n] = pattern;
    }
    
    return memo[n];
}

int n = int.Parse(Console.ReadLine());

int[,] output = MakePattern(n);

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < 2 * n - 1; j++)
    {
        outputBuilder.Append(output[i, j] == 1 ? '*' : ' ');
    }
    outputBuilder.AppendLine();
}

StreamWriter sw = new(Console.OpenStandardOutput());

sw.Write(outputBuilder.ToString());

sw.Close();
