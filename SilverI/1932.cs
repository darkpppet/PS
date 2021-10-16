using System;

int n = int.Parse(Console.ReadLine());

int[,] triangle = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j <= i; j++)
		triangle[i, j] = row[j];
}

for (int i = n - 1; i >= 1; i--)
{
	for (int j = 0; j < i; j++)
		triangle[i - 1, j] += Math.Max(triangle[i, j], triangle[i, j + 1]);
}

Console.WriteLine(triangle[0, 0]);
