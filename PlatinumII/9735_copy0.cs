using System;
using System.Collections.Generic;
using System.Text;

int n = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int t = 0; t < n; t++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	decimal a = decimal.Parse(input[0]);
	decimal b = decimal.Parse(input[1]);
	decimal c = decimal.Parse(input[2]);
	decimal d = decimal.Parse(input[3]);
	
	decimal Calc(decimal x) => a * x * x * x + b * x * x + c * x + d;
	
	SortedSet<decimal> xes = new();
	decimal x1 = 0;
	
	for (int i = -1_000_000; i <= 1_000_000; i++)
	{
		if (Calc(i) == 0)
		{
			x1 = i;
			xes.Add(i);
			break;
		}
	}
	
	decimal p = a * x1 + b;
	decimal q = c + p * x1;
	
	if (p * p - 4 * a * q >= 0)
	{
		xes.Add((-p - (decimal)Math.Sqrt((double)(p * p - 4 * a * q))) / (2 * a));
		xes.Add((-p + (decimal)Math.Sqrt((double)(p * p - 4 * a * q))) / (2 * a));
	}
	
	foreach (var x in xes)
		outputBuilder.Append($"{x} ");
	outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
