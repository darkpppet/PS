using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);
int v = int.Parse(input[2]);

int[,] graphMatrix = new int[n, n];

for (int i = 0; i < m; i++)
{
	input = Console.ReadLine().Split(" ");
	int n1 = int.Parse(input[0]) - 1;
	int n2 = int.Parse(input[1]) - 1;
	
	graphMatrix[n1, n2] = 1;
	graphMatrix[n2, n1] = 1;
}

int[] checkedPos = new int[n];
Console.Write($"{v} ");
checkedPos[v - 1] = 1;
Stack<int> dfsStack = new(new[] { v - 1 });

while (dfsStack.Count > 0)
{
	int before = dfsStack.Peek();
	bool haveNext = false;
	
	for (int i = 0; i < n; i++)
	{
		if (graphMatrix[before, i] == 1 && checkedPos[i] == 0)
		{
			Console.Write($"{i + 1} ");
			checkedPos[i] = 1;
			dfsStack.Push(i);
			haveNext = true;
			break;
		}
	}
	
	if (!haveNext)
		dfsStack.Pop();
}
Console.WriteLine();

checkedPos = new int[n];
Console.Write($"{v} ");
checkedPos[v - 1] = 1;
List<int> bfsBefore = new() { v - 1 };

while (bfsBefore.Count > 0)
{
	List<int> tempBefore = new();
	
	foreach (int i in bfsBefore)
	{
		for (int j = 0; j < n; j++)
		{
			if (graphMatrix[i, j] == 1 && checkedPos[j] == 0)
			{
				Console.Write($"{j + 1} ");
				checkedPos[j] = 1;
				tempBefore.Add(j);
			}
		}
	}
	
	bfsBefore = new(tempBefore);
}
Console.WriteLine();
