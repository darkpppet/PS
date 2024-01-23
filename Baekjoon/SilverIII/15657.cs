using System;
using System.Text;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
Array.Sort(arr);

List<int[]> result = new();

void Make(int[] sequence, int startIndex, int count)
{
	if (count == m)
	{
		result.Add(sequence);
		return;
	}
	
	for (int i = startIndex; i < n; i++)
	{
		int[] newSequence = (int[])sequence.Clone();
		newSequence[count] = arr[i];
		Make(newSequence, i, count + 1);
	}
}

Make(new int[m], 0, 0);

StringBuilder outputBuilder = new();

foreach (int[] sequence in result)
{
	foreach (int num in sequence)
		outputBuilder.Append($"{num} ");
	
	outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
