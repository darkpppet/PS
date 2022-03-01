using System;
using System.Text;
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

int t = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int testCount = 0; testCount < t; testCount++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	BigInteger n = BigInteger.Parse(input[0]);
	BigInteger m = BigInteger.Parse(input[1]);
	
	if (n == 0 && m == 1)
	{
		outputBuilder.AppendLine("1");
		continue;
	}
	else if (n == 0 || m == 1)
	{
		outputBuilder.AppendLine("0");
		continue;
	}
	
	List<BigInteger> n97 = new();
	List<BigInteger> m97 = new();

	BigInteger tempn = n - 1;
	BigInteger tempm = m - 2;
	
	while (tempn != 0 || tempm != 0)
	{
		n97.Add(tempn % 97);
		m97.Add(tempm % 97);
		
		tempn /= 97;
		tempm /= 97;
	}
	
	BigInteger a97 = 1;
	
	for (int i = 0; i < n97.Count; i++)
	{
		a97 *= C(n97[i], m97[i]);
		a97 %= 97;
	}
	
	List<BigInteger> n1031 = new();
	List<BigInteger> m1031 = new();

	tempn = n - 1;
	tempm = m - 2;
	
	while (tempn != 0 || tempm != 0)
	{
		n1031.Add(tempn % 1031);
		m1031.Add(tempm % 1031);
		
		tempn /= 1031;
		tempm /= 1031;
	}
	
	BigInteger a1031 = 1;
	
	for (int i = 0; i < n1031.Count; i++)
	{
		a1031 *= C(n1031[i], m1031[i]);
		a1031 %= 1031;
	}
	
	BigInteger result = (36085 * a97 + 63923 * a1031) % 100007;
	
	outputBuilder.AppendLine(result.ToString());
}

Console.Write(outputBuilder.ToString());
