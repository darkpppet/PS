using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

HashSet<int> hashSet = new() { n };
int count = 0;

while (true)
{
	HashSet<int> tempSet = new();
	
	if (hashSet.Contains(1))
		break;
	
	foreach (int i in hashSet)
	{
		if (i % 3 == 0)
			tempSet.Add(i / 3);
		
		if (i % 2 == 0)
			tempSet.Add(i / 2);
		
		tempSet.Add(i - 1);
	}
	
	hashSet = new(tempSet);
	count++;
}

Console.WriteLine(count);
