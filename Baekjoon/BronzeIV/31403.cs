using System;
using System.Collections.Generic;
using System.Linq;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] relationships = new int[n, n];

for (int i = 0; i < m; i++)
{
	input = Console.ReadLine().Split(' ');
	
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
	
	relationships[a - 1, b - 1] = 1;
	relationships[b - 1, a - 1] = 1;
}

int[] sums = new int[n];

for (int i = 0; i < n; i++)
{
	List<int> before = new() { i };
	int[] checkedPerson = new int[n];
	
	int count = 0;
	int level = 0;
	
	List<int> tempList;
	while (before.Count > 0)
	{ 
		tempList = new();
		
		foreach (int person in before)
		{
			checkedPerson[person] = 1;
			count += level;
			
			for (int j = 0; j < n; j++)
			{
				if (relationships[person, j] == 1 && checkedPerson[j] != 1)
					tempList.Add(j);
			}
		}
		
		before = new(tempList);
		level++;
	}
	
	sums[i] = count;
}

Console.WriteLine(Array.IndexOf(sums, sums.Min()) + 1);
