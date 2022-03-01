using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int> absHeap = new() { 0 };

void Swap(int index1, int index2)
{
	int temp = absHeap[index1];
	absHeap[index1] = absHeap[index2];
	absHeap[index2] = temp;
}

int Compare(int num1, int num2)
{
	if (Math.Abs(num1) == Math.Abs(num2))
	{
		if (num1 == num2)
			return 0;
		else
			return num1 < num2 ? -1 : 1;
	}
	else
	{
		return Math.Abs(num1) < Math.Abs(num2) ? -1 : 1;
	}
}

void AddToAbsHeap(int num)
{
	absHeap.Add(num);
	
	for (int index = absHeap.Count - 1; index > 1; index /= 2)
	{
		if (Compare(num, absHeap[index / 2]) < 0)
			Swap(index, index / 2);
		else
			break;
	}
}

int PopToAbsHeap()
{
	int min = absHeap[1];
	absHeap[1] = absHeap[^1];
	absHeap.RemoveAt(absHeap.Count - 1);
	
	int newindex;
	
	for (int index = 1; index <= (absHeap.Count - 1) / 2; index = newindex)
	{
		newindex = index * 2 + (index * 2 + 1 < absHeap.Count && Compare(absHeap[index * 2], absHeap[index * 2 + 1]) > 0 ? 1 : 0);
		
		if (Compare(absHeap[index], absHeap[newindex]) > 0)
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
		outputBuilder.AppendLine(absHeap.Count == 1 ? "0" : PopToAbsHeap().ToString());
	else
		AddToAbsHeap(x);
}

Console.Write(outputBuilder.ToString());
