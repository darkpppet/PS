using System;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] paper = new int[n, m];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < m; j++)
		paper[i, j] = row[j];
}

int max = 0;

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		int sum = 0;
		
		if (i + 1 < n && j + 1 < m)
		{
			sum = paper[i, j] + paper[i + 1, j] + paper[i, j + 1] + paper[i + 1, j + 1];
			max = max > sum ? max : sum;
		}
		
		if (i + 3 < n)
		{
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 2, j] + paper[i + 3, j];
			max = max > sum ? max : sum;
		}
		
		if (j + 3 < m)
		{
			sum = paper[i, j] + paper[i, j + 1] + paper[i, j + 2] + paper[i, j + 3];
			max = max > sum ? max : sum;
		}
		
		if (i + 1 < n && j + 2 < m)
		{
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 1, j + 1] + paper[i + 1, j + 2];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i, j + 1] + paper[i, j + 2] + paper[i + 1, j];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i, j + 1] + paper[i, j + 2] + paper[i + 1, j + 2];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i, j + 1] + paper[i + 1, j + 1] + paper[i + 1, j + 2];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i, j + 1] + paper[i, j + 2] + paper[i + 1, j + 1];
			max = max > sum ? max : sum;
		}
		
		if (i - 1 >= 0 && j + 2 < m)
		{
			sum = paper[i - 1, j + 2] + paper[i, j] + paper[i, j + 1] + paper[i, j + 2];
			max = max > sum ? max : sum;
			
			sum = paper[i - 1, j + 1] + paper[i - 1, j + 2] + paper[i, j] + paper[i, j + 1];
			max = max > sum ? max : sum;
			
			sum = paper[i - 1, j + 1] + paper[i, j] + paper[i, j + 1] + paper[i, j + 2];
			max = max > sum ? max : sum;
		}
		
		if (i + 2 < n && j + 1 < m)
		{
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 2, j] + paper[i + 2, j + 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 2, j] + paper[i, j + 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i, j + 1] + paper[i + 1, j + 1] + paper[i + 2, j + 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 1, j + 1] + paper[i + 2, j + 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 2, j] + paper[i + 1, j + 1];
			max = max > sum ? max : sum;
		}
		
		if (i + 2 < n && j - 1 >= 0)
		{
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 2, j] + paper[i + 2, j - 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 1, j - 1] + paper[i + 2, j - 1];
			max = max > sum ? max : sum;
			
			sum = paper[i, j] + paper[i + 1, j] + paper[i + 1, j - 1] + paper[i + 2, j];
			max = max > sum ? max : sum;
		}
	}
}

Console.WriteLine(max);
