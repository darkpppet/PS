using System;
using System.Collections.Generic;

HashSet<int> remainders = new() { int.Parse(Console.ReadLine()) };

int count = 0;

while (!remainders.Contains(0))
{
	count++;
	
	HashSet<int> tempSet = new();
	
	foreach (int i in remainders)
	{
		for (int j = (int)Math.Sqrt(i); j > 0; j--)
			tempSet.Add(i - j * j);
	}
	
	remainders = new(tempSet);
}

Console.WriteLine(count);
