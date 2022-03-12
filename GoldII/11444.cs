using System;
using System.Numerics;
using System.Collections.Generic;

Dictionary<BigInteger, long> memo = new()
{
	[0] = 0,
	[1] = 1
};

long Fibonacci(BigInteger num)
{
	if (!memo.ContainsKey(num))
	{
		if (num % 2 == 0)
		{
			long fnM1 = Fibonacci(num / 2 - 1);
			long fn = Fibonacci(num / 2);
			
			memo[num] = (fn * (2 * fnM1 + fn)) % 1_000_000_007;
		}
		else
		{
			long fnP1 = Fibonacci(num / 2 + 1);
			long fn = Fibonacci(num / 2);
			
			memo[num] = (fn * fn + fnP1 * fnP1) % 1_000_000_007;
		}
	}
	
	return memo[num];
}

Console.WriteLine(Fibonacci(BigInteger.Parse(Console.ReadLine())));
