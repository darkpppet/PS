using System;
using System.Numerics;

string[] input = Console.ReadLine().Split(' ');

BigInteger n = BigInteger.Parse(input[0]);
BigInteger m = BigInteger.Parse(input[1]);

m = m < n - m ? m : n - m;

BigInteger result = 1;

for (BigInteger i = n; i >= n - m + 1; i--)
	result *= i;

for (BigInteger i = 2; i <= m; i++)
	result /= i;

Console.WriteLine(result);
