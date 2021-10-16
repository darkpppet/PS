using System;
using System.Collections.Generic;

int count = int.Parse(Console.ReadLine());

Dictionary<int, (int Count0, int Count1)> Memo = new()
{
	[0] = (1, 0),
	[1] = (0, 1)
};

(int Count0, int Count1) Fibonacci(int n)
{
	if (!Memo.ContainsKey(n))
	{
		return Memo[n];
	}
	else
	{
		var before1 = Fibonacci(n - 1);
		var before2 = Fibonacci(n - 2);
		
		Memo[n] = (before1.Count0 + before2.Count0, before1.Count1 + before2.Count1);
	}
	
	return Memo[n];
}

for (int i = 0; i < count; i++)
{
	var result = Fibonacci(int.Parse(Console.ReadLine()));

	Console.WriteLine(result.Count0 + " " + result.Count1);
}
