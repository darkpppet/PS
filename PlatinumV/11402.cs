using System;
using System.Numerics;
using System.Collections.Generic;

BigInteger C(BigInteger n, BigInteger k)
{
	if (k > n)
		return 0;
	
	if (n - k < k)
		return C(n, n - k);
	
	BigInteger result = 1;
	
	for (BigInteger i = n - k + 1; i <= n; i++)
		result *= i;
	
	for (BigInteger i = 2; i <= k; i++)
		result /= i;
	
	return result;
}

string[] input = Console.ReadLine().Split(' ');

BigInteger n = BigInteger.Parse(input[0]);
BigInteger k = BigInteger.Parse(input[1]);
BigInteger m = BigInteger.Parse(input[2]);

List<BigInteger> nm = new();
List<BigInteger> km = new();

while (n != 0 || k != 0)
{
	nm.Add(n % m);
	km.Add(k % m);
	
	n /= m;
	k /= m;
}

BigInteger result = 1;

for (int i = 0; i < nm.Count; i++)
{
	result *= C(nm[i], km[i]);
	result %= m;
}

Console.WriteLine(result);
