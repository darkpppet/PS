using System;
using System.Collections.Generic;
using System.Linq;

int testCount = int.Parse(Console.ReadLine());

for (int i = 0; i < testCount; i++)
{
	int index = int.Parse(Console.ReadLine().Split(" ")[1]);	
	Queue<int> queue = new(Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x)));
	
	int printCount = 0;
	
	while (index != -1)
	{
		int temp = queue.Dequeue();
		index--;
		
		if (queue.Any() && temp < queue.Max())
		{
			if (index == -1)
				index = queue.Count();
			
			queue.Enqueue(temp);
		}
		else
		{
			printCount++;
		}
		
	}
	
	Console.WriteLine(printCount);
}
