using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int k = int.Parse(input[1]);

HashSet<int> hashSet = new() { n };
HashSet<int> beforeSet = new() { n };
int count = 0;

while (true)
{
	HashSet<int> tempSet = new();
	
	if (hashSet.Contains(k))
		break;
	
	foreach (int i in beforeSet)
	{
		if (i - 1 >= 0 && !hashSet.Contains(i - 1))
		{
			hashSet.Add(i - 1);
			tempSet.Add(i - 1);
		}
		
		if (i + 1 <= 100_000 && !hashSet.Contains(i + 1))
		{
			hashSet.Add(i + 1);
			tempSet.Add(i + 1);
		}
		
		if (i * 2 <= 100_000 && !hashSet.Contains(i * 2))
		{
			hashSet.Add(i * 2);
			tempSet.Add(i * 2);
		}
	}
	
	beforeSet = new(tempSet);
	count++;
}

Console.WriteLine(count);
