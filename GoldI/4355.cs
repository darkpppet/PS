using System;
using System.Collections.Generic;

int n;

while ((n = int.Parse(Console.ReadLine())) != 0)
{
	HashSet<int> hashSet = new();

	int phi = n;

	int sqrt = (int)Math.Sqrt(n);

	for (int i = 2; n > 1 && i <= sqrt; i++)
	{
		if (n % i == 0)
		{
			n /= i;
			hashSet.Add(i);
			i--;
		}
	}

	if (n != 1)
	{
		phi /= n;
		phi *= n - 1;
	}

	foreach (int p in hashSet)
	{
		phi /= p;
		phi *= p - 1;
	}

	Console.WriteLine(phi);
}
