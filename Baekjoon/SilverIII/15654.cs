using System;
using System.Text;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
Array.Sort(arr);

List<int[]> result = new();

void Make(int[] sequence, int[] checkedIndex, int count)
{
	if (count == m)
	{
		result.Add(sequence);
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (checkedIndex[i] == 0)
		{
			int[] newSequence = (int[])sequence.Clone();
			int[] newCheckedIndex = (int[])checkedIndex.Clone();
			
			newCheckedIndex[i] = 1;
			newSequence[count] = arr[i];
			
			Make(newSequence, newCheckedIndex, count + 1);
		}
	}
}

Make(new int[m], new int[n], 0);

StringBuilder outputBuilder = new();

foreach (int[] sequence in result)
{
	foreach (int num in sequence)
		outputBuilder.Append($"{num} ");
	
	outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
