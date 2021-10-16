using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int k = int.Parse(input[1]);

Dictionary<int, int> pathCounts = new()
{
	[n] = 1
};

List<int> beforeList = new() { n };
int count = 0;

while (!pathCounts.ContainsKey(k))
{
	List<int> tempList = new();
	
	Dictionary<int, int> beforeCounts = new();
	foreach (int i in beforeList)
		beforeCounts[i] = pathCounts[i];
	
	foreach (int i in beforeList)
	{
		if (i - 1 >= 0)
		{
			if (pathCounts.ContainsKey(i - 1))
			{
				pathCounts[i - 1] += beforeCounts[i];
			}
			else
			{
				pathCounts[i - 1] = beforeCounts[i];
				tempList.Add(i - 1);
			}
		}
		
		if (i + 1 <= 100_000)
		{
			if (pathCounts.ContainsKey(i + 1))
			{
				pathCounts[i + 1] += beforeCounts[i];
			}
			else
			{
				pathCounts[i + 1] = beforeCounts[i];
				tempList.Add(i + 1);
			}
		}
		
		if (2 * i <= 100_000)
		{
			if (pathCounts.ContainsKey(2 * i))
			{
				pathCounts[2 * i] += beforeCounts[i];
			}
			else
			{
				pathCounts[2 * i] = beforeCounts[i];
				tempList.Add(2 * i);
			}
		}
	}
	
	beforeList = new(tempList);
	count++;
}

Console.WriteLine(count);
Console.WriteLine(pathCounts[k]);
