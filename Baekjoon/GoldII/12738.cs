using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
List<int> lengthEnd = new();
lengthEnd.Add(arr[0]);

for (int i = 1; i < n; i++)
{
	if (arr[i] > lengthEnd[^1])
	{
		lengthEnd.Add(arr[i]);
	}
	else
	{
		int index = ~lengthEnd.BinarySearch(arr[i]);
		
		if (index >= 0)
			lengthEnd[index] = arr[i];
	}
}

Console.WriteLine(lengthEnd.Count);
