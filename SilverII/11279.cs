using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int> maxHeap = new() { 0 };

void Swap(int index1, int index2)
{
	int temp = maxHeap[index1];
	maxHeap[index1] = maxHeap[index2];
	maxHeap[index2] = temp;
}

void AddToMaxHeap(int num)
{
	maxHeap.Add(num);
	
	for (int index = maxHeap.Count - 1; index > 1; index /= 2)
	{
		if (num > maxHeap[index / 2])
			Swap(index, index / 2);
		else
			break;
	}
}

int PopToMaxHeap()
{
	int max = maxHeap[1];
	maxHeap[1] = maxHeap[^1];
	maxHeap.RemoveAt(maxHeap.Count - 1);
	
	int newindex;
	
	for (int index = 1; index <= (maxHeap.Count - 1) / 2; index = newindex)
	{
		newindex = index * 2 + (index * 2 + 1 < maxHeap.Count && maxHeap[index * 2] < maxHeap[index * 2 + 1] ? 1 : 0);
		
		if (maxHeap[index] < maxHeap[newindex])
			Swap(index, newindex);
		else
			break;
	}
	
	return max;
}

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
	int x = int.Parse(Console.ReadLine());
	
	if (x == 0)
		outputBuilder.AppendLine(maxHeap.Count == 1 ? "0" : PopToMaxHeap().ToString());
	else
		AddToMaxHeap(x);
}

Console.Write(outputBuilder.ToString());
