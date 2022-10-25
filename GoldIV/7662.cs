using System;
using System.Text;
using System.Collections.Generic;

class DPQueue
{
	private List<(int Left, int Right)> dpQueue = new() { (0, 0) };
	
	private int count = 0;
	public int Count { get => count; }
	
	private int LastIndex { get => (Count + 1) / 2; }
	
	private void Swap(int index1, int index2, bool isLeft)
	{
		if (isLeft)
		{
			int temp = dpQueue[index1].Left;
			dpQueue[index1] = (dpQueue[index2].Left, dpQueue[index1].Right);
			dpQueue[index2] = (temp, dpQueue[index2].Right);
		}
		else
		{
			int temp = dpQueue[index1].Right;
			dpQueue[index1] = (dpQueue[index1].Left, dpQueue[index2].Right);
			dpQueue[index2] = (dpQueue[index2].Left, temp);
		}
	}
	
	public int PeekMinValue() => dpQueue[1].Left;
	public int PeekMaxValue() => dpQueue[1].Right;
	
	public int DequeueMinValue()
	{
		int min = PeekMinValue();
		
		dpQueue[1] = (dpQueue[LastIndex].Left, dpQueue[1].Right);
		
		if (Count % 2 == 0)
			dpQueue[LastIndex] = (dpQueue[LastIndex].Right, dpQueue[LastIndex].Right);
		else
			dpQueue.RemoveAt(LastIndex);
		
		count--;
		
		for (int index = 1; index <= LastIndex / 2; )
		{
			int newindex = index * 2 + (index * 2 + 1 <= LastIndex && dpQueue[index * 2].Left > dpQueue[index * 2 + 1].Left ? 1 : 0);
			
			if (dpQueue[index].Left > dpQueue[newindex].Left)
				Swap(index, newindex, true);
			else
				break;
			
			index = newindex;
			
			if (dpQueue[index].Left > dpQueue[index].Right)
				dpQueue[index] = (dpQueue[index].Right, dpQueue[index].Left);
		}
		
		return min;
	}
	
	public int DequeueMaxValue()
	{
		int max = PeekMaxValue();
		
		dpQueue[1] = (dpQueue[1].Left, dpQueue[LastIndex].Right);
		
		if (Count % 2 == 0)
			dpQueue[LastIndex] = (dpQueue[LastIndex].Left, dpQueue[LastIndex].Left);
		else
			dpQueue.RemoveAt(LastIndex);
		
		count--;
		
		for (int index = 1; index <= LastIndex / 2; )
		{
			int newindex = index * 2 + (index * 2 + 1 <= LastIndex && dpQueue[index * 2].Right < dpQueue[index * 2 + 1].Right ? 1 : 0);
			
			if (dpQueue[index].Right < dpQueue[newindex].Right)
				Swap(index, newindex, false);
			else
				break;
			
			index = newindex;
			
			if (dpQueue[index].Left > dpQueue[index].Right)
				dpQueue[index] = (dpQueue[index].Right, dpQueue[index].Left);
		}
		
		return max;
	}

	public void Enqueue(int num)
	{
		count++;
		int index = LastIndex;
		bool isLeft = true;
		
		if (Count % 2 != 0)
		{
			dpQueue.Add((num, num));
			
			if (index <= 1 || (dpQueue[index / 2].Left <= num && num <= dpQueue[index / 2].Right))
			{
				return;
			}
			else
			{
				isLeft = num < dpQueue[index / 2].Left ? true : false;
				Swap(index, index / 2, isLeft);
				
				dpQueue[index] = isLeft ? (dpQueue[index].Left, dpQueue[index].Left) : (dpQueue[index].Right, dpQueue[index].Right);
				
				index /= 2;
			}
		}
		else
		{
			int lastnum = dpQueue[LastIndex].Left;
			
			dpQueue[LastIndex] = num < lastnum ? (num, lastnum) : (lastnum, num);
			isLeft = num < lastnum ? true : false;
		}
		
		for (; index > 1; index /= 2)
		{
			if (isLeft ? num < dpQueue[index / 2].Left : num > dpQueue[index / 2].Right)
				Swap(index, index / 2, isLeft);
			else
				return;
		}
	}
}

class Program
{
	static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());
		
		StringBuilder outputBuilder = new();
		
		for (int i = 0; i < t; i++)
		{
			int k = int.Parse(Console.ReadLine());
			
			DPQueue dpQueue = new();
			
			for (int j = 0; j < k; j++)
			{
				string[] input = Console.ReadLine().Split(" ");
				
				switch (input[0])
				{
					case "I":
						dpQueue.Enqueue(int.Parse(input[1]));
						break;
						
					case "D":
						if (dpQueue.Count > 0)
						{
							switch (input[1])
							{
								case "1":
									dpQueue.DequeueMaxValue();
									break;
								
								case "-1":
									dpQueue.DequeueMinValue();
									break;
							}
						}
						break;
				}	
			}
			
			outputBuilder.AppendLine(dpQueue.Count == 0 ? "EMPTY" : dpQueue.PeekMaxValue() + " " + dpQueue.PeekMinValue());
		}
		
		Console.Write(outputBuilder.ToString());
	}
}
