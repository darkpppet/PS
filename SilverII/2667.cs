using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

int[,] map = new int[n,n];

for (int i = 0; i < n; i++)
{
	int[] inputLine = Array.ConvertAll(Console.ReadLine().ToCharArray(), x => x - '0');
	
	for (int j = 0; j < n; j++)
		map[i, j] = inputLine[j];
}

int[,] counted = new int[n, n];

List<int> result = new();

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (map[i, j] == 1 && counted[i, j] == 0)
		{
			int count = 0;
			HashSet<(int I, int J)> beforeSet = new() { (i, j) };
			
			while (beforeSet.Count > 0)
			{
				count += beforeSet.Count;
				
				HashSet<(int I, int J)> tempSet = new();
				
				foreach ((int I, int J) in beforeSet)
				{
					counted[I, J] = 1;
					
					if (I - 1 >= 0 && map[I - 1, J] == 1 && counted[I - 1, J] != 1)
						tempSet.Add((I - 1, J));
					
					if (I + 1 < n && map[I + 1, J] == 1 && counted[I + 1, J] != 1)
						tempSet.Add((I + 1, J));
					
					if (J - 1 >= 0 && map[I, J - 1] == 1 && counted[I, J - 1] != 1)
						tempSet.Add((I, J - 1));
					
					if (J + 1 < n && map[I, J + 1] == 1 && counted[I, J + 1] != 1)
						tempSet.Add((I, J + 1));
				}
				
				beforeSet = new(tempSet);
			}
			
			result.Add(count);
		}
	}
}

result.Sort();

Console.WriteLine(result.Count);
foreach(int num in result)
	Console.WriteLine(num);
