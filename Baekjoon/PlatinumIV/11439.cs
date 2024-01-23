using System;
using System.Numerics;
using System.Collections.Generic;

Dictionary<(BigInteger n, BigInteger k), BigInteger> memo = new();

BigInteger C(BigInteger n, BigInteger k, BigInteger m)
{
	if (n - k < k)
		return C(n, n - k, m);
	
	if (!memo.ContainsKey((n, k)))
		memo[(n, k)] = k == 0 ? 1 : (C(n - 1, k, m) + C(n - 1, k - 1, m)) % m;
	
	return memo[(n, k)];
}

string[] input = Console.ReadLine().Split(' ');

BigInteger n = BigInteger.Parse(input[0]);
BigInteger k = BigInteger.Parse(input[1]);
BigInteger m = BigInteger.Parse(input[2]);

Console.WriteLine(C(n, k, m));
