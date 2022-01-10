string[] input = Console.ReadLine().Split();

int n = int.Parse(input[0]);
int e = int.Parse(input[1]);

long[,] matrix = new long[n + 1, n + 1];

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        matrix[i, j] = i == j ? 0 : 1_000_000_000_000;
    }
}

for (int i = 0; i < e; i++)
{
    input = Console.ReadLine().Split();
    
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    long c = long.Parse(input[2]);
    
    matrix[a, b] = Math.Min(matrix[a, b], c);
    matrix[b, a] = Math.Min(matrix[b, a], c);
}

input = Console.ReadLine().Split();
int v1 = int.Parse(input[0]);
int v2 = int.Parse(input[1]);

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

long result = Math.Min(matrix[1, v1] + matrix[v1, v2] + matrix[v2, n], matrix[1, v2] + matrix[v2, v1] + matrix[v1, n]);

Console.WriteLine(result < 1_000_000_000_000 ? result : -1);
