using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int>[] tree = new List<int>[n];

for (int i = 0; i < n; i++)
	tree[i] = new();

for (int i = 0; i < n - 1; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int a = int.Parse(input[0]) - 1;
	int b = int.Parse(input[1]) - 1;
	
	tree[a].Add(b);
	tree[b].Add(a);
}

int[] parent = new int[n];

List<int> before = new() { 0 };

while (before.Count > 0)
{
	List<int> tempBefore = new();
	
	foreach (int i in before)
	{
		foreach (int j in tree[i])
		{
			parent[j] = i + 1;
			tree[j].Remove(i);
			tempBefore.Add(j);
		}
	}

	before = new(tempBefore);
}

StringBuilder outputBuilder = new();

for (int i = 1; i < n; i++)
	outputBuilder.AppendLine(parent[i].ToString());

Console.Write(outputBuilder.ToString());
