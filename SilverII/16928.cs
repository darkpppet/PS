using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int portalCount = int.Parse(input[0]) + int.Parse(input[1]);

Dictionary<int, int> portalDictionary = new();

for (int i = 0; i < portalCount; i++)
{
	input = Console.ReadLine().Split(" ");
	portalDictionary[int.Parse(input[0])] = int.Parse(input[1]);
}

HashSet<int> beforeSet = new() { 1 };

int count = 0;

while (!beforeSet.Contains(100))
{
	count++;
	
	HashSet<int> tempSet = new();
	
	foreach (int num in beforeSet)
	{
		for (int i = 1; i <= 6; i++)
		{
			int next = portalDictionary.ContainsKey(num + i) ? portalDictionary[num + i] : num + i;
			
			if (next <= 100)
				tempSet.Add(next);
		}
	}
	
	beforeSet = new(tempSet);
}

Console.WriteLine(count);
