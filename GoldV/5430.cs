using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	string p = Console.ReadLine().Replace("RR", "");
	
	int n = int.Parse(Console.ReadLine());
	
	string input = Console.ReadLine();
	List<int> array = n == 0 ? new() : new(Array.ConvertAll(input.Substring(1, input.Length - 2).Split(','), int.Parse)); 
	
	if (p.Count(x => x == 'D') <= n)
	{
		int[] dCounts = Array.ConvertAll(p.Split('R'), x => x.Length);
		
		int leftCount = 0;
		int rightCount = 0;
		
		for (int j = 0; j < dCounts.Length; j++)
		{
			if (j % 2 == 0)
				leftCount += dCounts[j];
			else
				rightCount += dCounts[j];
		}
		
		array.RemoveRange(0, leftCount);
		array.RemoveRange(array.Count - rightCount, rightCount);
		
		if (p.Count(x => x == 'R') % 2 != 0)
			array.Reverse();
		
		if (array.Count > 0)
		{
			StringBuilder outputBuilder = new();
			outputBuilder.Append("[");
			for (int j = 0; j < array.Count - 1; j++)
				outputBuilder.Append($"{array[j]},");
			outputBuilder.Append($"{array[^1]}]");
			Console.WriteLine(outputBuilder.ToString());
		}
		else
		{
			Console.WriteLine("[]");
		}
	}
	else
	{
		Console.WriteLine("error");
	}
}
