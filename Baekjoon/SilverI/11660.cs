using System;
using System.Text;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] table = new int[n, n + 1];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
		table[i, j + 1] = table[i, j] + row[j];
}

StringBuilder outputBuilder = new();

for (int t = 0; t < m; t++)
{
	input = Console.ReadLine().Split(' ');
	
	int x1 = int.Parse(input[0]) - 1;
	int y1 = int.Parse(input[1]) - 1;
	int x2 = int.Parse(input[2]) - 1;
	int y2 = int.Parse(input[3]);
	
	int sum = 0;
	
	for (int i = x1; i <= x2; i++)
		sum += table[i, y2] - table[i, y1];
	
	outputBuilder.AppendLine(sum.ToString());
}

Console.Write(outputBuilder.ToString());
