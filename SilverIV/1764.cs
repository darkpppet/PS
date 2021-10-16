using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

HashSet<string> hashset = new();
List<string> result = new();

for (int i = 0; i < n; i++)
	hashset.Add(Console.ReadLine());

for (int i = 0; i < m; i++)
{
	string tempword = Console.ReadLine();
	
	if (hashset.Contains(tempword))
		result.Add(tempword);
}

result.Sort();

Console.WriteLine(result.Count);

foreach (string word in result)
	Console.WriteLine(word);
