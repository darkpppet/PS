using System;
using System.Collections.Generic;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	int n = int.Parse(Console.ReadLine());
	
	Dictionary<string, int> dictionary = new();
	
	for (int j = 0; j < n; j++)
	{
		string[] input = Console.ReadLine().Split(" ");
		
		if (!dictionary.ContainsKey(input[1]))
			dictionary[input[1]] = 1;
		else
			dictionary[input[1]]++;
		
	}
	
	int result = 1;
	
	foreach (int num in dictionary.Values)
			result *= num + 1;
		
	Console.WriteLine(result - 1);
}
