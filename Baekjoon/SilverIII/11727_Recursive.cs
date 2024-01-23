using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

Dictionary<int, int> Memo = new()
{
	[0] = 1,
	[1] = 1
};

int Calc(int n)
{
	if (Memo.ContainsKey(n))
	{
		return Memo[n];
	}
	else
	{
		int before1 = Calc(n - 1);
		int before2 = Calc(n - 2);
		
		Memo[n] = (before1 + 2 * before2) % 10007;
	}
	
	return Memo[n];
}

Console.WriteLine(Calc(n));
