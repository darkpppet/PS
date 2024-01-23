using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int> minHeap = new() { 0 };

void Swap(int index1, int index2)
{
	int temp = minHeap[index1];
	minHeap[index1] = minHeap[index2];
	minHeap[index2] = temp;
}

void AddToMinHeap(int num)
{
	minHeap.Add(num);
	
	for (int index = minHeap.Count - 1; index > 1; index /= 2)
	{
		if (num < minHeap[index / 2])
			Swap(index, index / 2);
		else
			break;
	}
}

int PopToMinHeap()
{
	int min = minHeap[1];
	minHeap[1] = minHeap[^1];
	minHeap.RemoveAt(minHeap.Count - 1);
	
	int newindex;
	
	for (int index = 1; index <= (minHeap.Count - 1) / 2; index = newindex)
	{
		newindex = index * 2 + (index * 2 + 1 < minHeap.Count && minHeap[index * 2] > minHeap[index * 2 + 1] ? 1 : 0);
		
		if (minHeap[index] > minHeap[newindex])
			Swap(index, newindex);
		else
			break;
	}
	
	return min;
}

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
	int x = int.Parse(Console.ReadLine());
	
	if (x == 0)
		outputBuilder.AppendLine(minHeap.Count == 1 ? "0" : PopToMinHeap().ToString());
	else
		AddToMinHeap(x);
}

Console.Write(outputBuilder.ToString());
