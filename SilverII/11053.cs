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
		try
		{
			lengthEnd[~lengthEnd.BinarySearch(arr[i])] = arr[i];
		}
		catch (Exception) { }
	}
}

Console.WriteLine(lengthEnd.Count);
