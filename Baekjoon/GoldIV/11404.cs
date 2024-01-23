using System.Text;

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());

long[,] matrix = new long[n + 1, n + 1];

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        matrix[i, j] = i == j ? 0 : 1_000_000_000_000;
    }
}

for (int i = 0; i < m; i++)
{
    string[] input = Console.ReadLine().Split();
    
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    long c = long.Parse(input[2]);
    
    matrix[a, b] = Math.Min(matrix[a, b], c);
}

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (j == i)
            continue;
        
        for (int k = 1; k <= n; k++)
        {
            if (k == i)
                continue;
            
            matrix[j, k] = Math.Min(matrix[j, k], matrix[j, i] + matrix[i, k]);
        }
    }
}

StringBuilder outputBuilder = new();

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        outputBuilder.Append($"{(matrix[i, j] == 1_000_000_000_000 ? 0 : matrix[i, j])} ");
    }
    outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
