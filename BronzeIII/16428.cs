using System;
using System.Numerics;

string[] input = Console.ReadLine().Split(" ");

BigInteger a = BigInteger.Parse(input[0]);
BigInteger b = BigInteger.Parse(input[1]);

BigInteger q = a / b;
BigInteger r = a % b;

if (r < 0)
{
	if (b > 0)
	{
		r += b;
		q -= 1;
	}
	else
	{
		r -= b;
		q += 1;
	}
}

Console.WriteLine(q);
Console.WriteLine(r);
