using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<(int Start, int End)> list = new();

for (int i = 0; i < n; i++)
{
	string[] input = Console.ReadLine().Split(" ");
	
	list.Add((int.Parse(input[0]), int.Parse(input[1])));
}

list.Sort((a, b) => 
		  {
			  if (a.End == b.End)
				  return a.Start < b.Start ? -1 : 1;
			  else
				  return a.End < b.End ? -1 : 1;
		  });

int count = 1;
int index = 0;

var now = list[0];

for (int i = 1; i < list.Count; i++)
{
	if (list[i].Start >= now.End)
	{
		count++;
		now = list[i];
	}
}

Console.WriteLine(count);
