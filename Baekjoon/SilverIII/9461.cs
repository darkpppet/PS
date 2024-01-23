using System;
using System.Collections.Generic;

int t = int.Parse(Console.ReadLine());

Dictionary<int, long> sequence = new()
{
	[0] = 0,
	[1] = 1,
	[2] = 1,
	[3] = 1,
	[4] = 2
};

long CalcPadovan(int num)
{
	if (!sequence.ContainsKey(num))
		sequence[num] = CalcPadovan(num - 5) + CalcPadovan(num - 1);
	
	return sequence[num];
}

for (int i = 0; i < t; i++)
	Console.WriteLine(CalcPadovan(int.Parse(Console.ReadLine())));
