using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int k = int.Parse(input[1]);

HashSet<int> hashSet = new();

if (n == 0)
{
	hashSet.Add(n);
}
else
{
	for (int i = n; i <= 100_000; i *= 2)
		hashSet.Add(i);
}
	
HashSet<int> beforeSet = new(hashSet);

int count = 0;

while (!hashSet.Contains(k))
{
	HashSet<int> tempSet = new();
	
	foreach (int i in beforeSet)
	{
		if (i - 1 == 0 && !hashSet.Contains(i - 1))
		{
			hashSet.Add(i - 1);
			tempSet.Add(i - 1);
		}
		
		if (i - 1 > 0)
		{
			for (int j = i - 1; j <= 100_000 && !hashSet.Contains(j); j *= 2)
			{
				hashSet.Add(j);
				tempSet.Add(j);
			}
		}
		
		if (i + 1 <= 100_000)
		{
			for (int j = i + 1; j <= 100_000 && !hashSet.Contains(j); j *= 2)
			{
				hashSet.Add(j);
				tempSet.Add(j);
			}
		}
	}
	
	beforeSet = new(tempSet);
	count++;
}

Console.WriteLine(count);
