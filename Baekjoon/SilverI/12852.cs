using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

Dictionary<int, Dictionary<int, int>> history = new()
{
	[0] = new()
	{
		[n] = 0
	}
};

int count = 0;

while (!history[count].ContainsKey(1))
{
	Dictionary<int, int> temp = new();
	
	foreach (int i in history[count].Keys)
	{
		if (i % 3 == 0)
			temp[i / 3] = 3;
		
		if (i % 2 == 0)
			temp[i / 2] = 2;
		
		temp[i - 1] =  1;
	}
	
	count++;
	
	history[count] = temp;
}

Console.WriteLine(count);

int now = 1;

List<int> path = new() { 1 };

while (now != n)
{
	now = history[count][now] switch
	{
		1 => now + 1,
		2 => now * 2,
		3 => now * 3
	};
	
	path.Add(now);
	
	count--;
}

path.Reverse();

foreach (int i in path)
	Console.Write($"{i} ");
Console.WriteLine();
