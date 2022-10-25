using System;
using System.Text;

char[,] MakePattern(int n)
{
    if (n == 1)
        return new char[,] { { '*' } };
    
    char[,] subPattern = MakePattern(n / 3);
    
    char[,] pattern = new char[n, n];

    for (int i = 0; i < n / 3; i++)
    {
        for (int j = 0; j < n / 3; j++)
        {
            pattern[i, j] = subPattern[i, j];
            pattern[i + n / 3, j] = subPattern[i, j];
            pattern[i + 2 * n / 3, j] = subPattern[i, j];
            
            pattern[i, j + n / 3] = subPattern[i, j];
            pattern[i + n / 3, j + n / 3] = ' ';
            pattern[i + 2 * n / 3, j + n / 3] = subPattern[i, j];
            
            pattern[i, j + 2 * n / 3] = subPattern[i, j];
            pattern[i + n / 3, j + 2 * n / 3] = subPattern[i, j];
            pattern[i + 2 * n / 3, j + 2 * n / 3] = subPattern[i, j];
        }
    }
    
    return pattern;
}

int n = int.Parse(Console.ReadLine());

char[,] output = MakePattern(n);

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        outputBuilder.Append(output[i, j]);
    }
    outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
