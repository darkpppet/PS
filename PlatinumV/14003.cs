using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
int[] arrIndex = new int[arr.Length];
List<int> lengthEnd = new() { arr[0] };

for (int i = 1; i < n; i++)
{
	if (arr[i] > lengthEnd[^1])
	{
		lengthEnd.Add(arr[i]);
		arrIndex[i] = lengthEnd.Count - 1;
	}
	else
	{
		int index = ~lengthEnd.BinarySearch(arr[i]);
		
		if (index >= 0)
		{
			lengthEnd[index] = arr[i];
			arrIndex[i] = index;
		}
		else
		{
			arrIndex[i] = ~index;
		}
	}
}

Console.WriteLine(lengthEnd.Count);

int[] lis = new int[lengthEnd.Count];

int indexLis = lengthEnd.Count - 1;

for (int i = n - 1; indexLis >= 0; i--)
{
	if (arrIndex[i] == indexLis)
	{
		lis[indexLis] = arr[i];
		indexLis--;
	}
}

StringBuilder outputBuilder = new();

foreach (int num in lis)
	outputBuilder.Append($"{num} ");

Console.WriteLine(outputBuilder.ToString());
