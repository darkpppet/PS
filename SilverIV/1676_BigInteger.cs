using System;
using System.Numerics;

BigInteger n = BigInteger.Parse(Console.ReadLine());

BigInteger result = 1;

for (BigInteger i = 1; i <= n; i++)
	result *= i;

char[] resultArr = result.ToString().ToCharArray();

int count = 0;

for (int i = 1; ; i++)
{
	if (resultArr[^i] == '0')
		count++;
	else
		break;
}

Console.WriteLine(count);
