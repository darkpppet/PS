using System;
using System.Collections.Generic;
using System.Linq;

int n = int.Parse(Console.ReadLine());

List<int> list = new() { 0 };

for (int i = 0; i < n; i++)
	list.Add(int.Parse(Console.ReadLine()));

Dictionary<int, int> memo = new();

int Calc(int level)
{
	if (!memo.ContainsKey(level))
	{
		List<int> tempList = new();
		
		if (level + 2 <= n)
			tempList.Add(list[level] + Calc(level + 2));
		
		if (level + 3 <= n)
			tempList.Add(list[level] + list[level + 1] + Calc(level + 3));
		
		memo[level] = tempList.Count == 0 ? list[level] + (level + 1 == n ? list[level + 1] : 0) : tempList.Max();
	}
	
	return memo[level];
}

Console.WriteLine(n > 1 ? (Calc(1) > Calc(2) ? Calc(1) : Calc(2)) : Calc(1));
