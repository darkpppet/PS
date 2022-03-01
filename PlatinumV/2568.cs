using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<(int Start, int End)> list = new();

Dictionary<int, int> dictionary = new();

for (int i = 0; i < n; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	list.Add((int.Parse(input[0]), int.Parse(input[1])));
	
	dictionary[int.Parse(input[1])] = int.Parse(input[0]);
}

list.Sort((a, b) =>
		  {
			  if (a.Start == b.Start)
				  return 0;
			  else
				  return a.Start < b.Start ? -1 : 1;
		  });

List<int> endList = new();

foreach ((_, int End) in list)
	endList.Add(End);

int[] listIndex = new int[endList.Count];
List<int> lengthEnd = new() { endList[0] };

for (int i = 1; i < n; i++)
{
	if (endList[i] > lengthEnd[^1])
	{
		lengthEnd.Add(endList[i]);
		listIndex[i] = lengthEnd.Count - 1;
	}
	else
	{
		int index = ~lengthEnd.BinarySearch(endList[i]);
		
		if (index >= 0)
		{
			lengthEnd[index] = endList[i];
			listIndex[i] = index;
		}
		else
		{
			listIndex[i] = ~index;
		}
	}
}

Console.WriteLine(lengthEnd.Count);

int[] lis = new int[lengthEnd.Count];

int indexLis = lengthEnd.Count - 1;

for (int i = n - 1; indexLis >= 0; i--)
{
	if (listIndex[i] == indexLis)
	{
		lis[indexLis] = dictionary[endList[i]];
		indexLis--;
	}
}

StringBuilder outputBuilder = new();

foreach (int num in lis)
	outputBuilder.AppendLine(num.ToString());

Console.Write(outputBuilder.ToString());
