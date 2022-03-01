using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	char[] p = Console.ReadLine().ToCharArray();
	
	int n = int.Parse(Console.ReadLine());
	
	string input = Console.ReadLine();
	List<int> array = n == 0 ? new() : new(Array.ConvertAll(input.Substring(1, input.Length - 2).Split(','), int.Parse)); 
	
	if (p.Count(x => x == 'D') <= n)
	{
		bool isFront = true;
		
		foreach (char function in p)
		{
			switch (function)
			{
				case 'R':
					isFront = !isFront;
					break;
				
				case 'D':
					array.RemoveAt(isFront ? 0 : array.Count - 1);
					break;
			}
		}
		
		if (!isFront)
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
