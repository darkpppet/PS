using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

int[,] matrix = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
		matrix[i, j] = row[j];
}

int[,] resultMatrix = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] vertexesChecked = new int[n];
	
	List<int> list = new() { i };
	
	while (list.Count > 0)
	{
		List<int> tempList = new();
		
		foreach (int vertex in list)
		{
			for (int j = 0; j < n; j++)
			{
				if (vertexesChecked[j] != 1 && matrix[vertex, j] == 1)
				{
					resultMatrix[i, j] = 1;
					vertexesChecked[j] = 1;
					tempList.Add(j);
				}
			}
		}
		
		list = new(tempList);
	}
}

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		Console.Write($"{resultMatrix[i, j]} ");
	
	Console.WriteLine();
}
