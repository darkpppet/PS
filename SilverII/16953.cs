using System;
using System.Collections.Generic;
using System.Linq;

string[] input = Console.ReadLine().Split(' ');

long a = long.Parse(input[0]);
long b = long.Parse(input[1]);

int count = 1;
List<long> before = new() { a };

while (before.Count > 0 && !before.Any(x => x == b))
{
	count++;
	
	List<long> tempBefore = new();
	
	foreach (long beforeA in before)
	{
		if (2 * beforeA <= b)
			tempBefore.Add(2 * beforeA);
		
		if (10 * beforeA + 1 <= b)
			tempBefore.Add(10 * beforeA + 1);
	}
	
	before = new(tempBefore);
}

Console.WriteLine(before.Any(x => x == b) ? count : -1);
