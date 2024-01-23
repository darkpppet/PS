using System;
using System.Collections.Generic;

HashSet<long> hashSet = new();

long n = long.Parse(Console.ReadLine());
long phi = n;

long sqrt = (long)Math.Sqrt(n);

for (long i = 2; n > 1 && i <= sqrt; i++)
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

foreach (long p in hashSet)
{
	phi /= p;
	phi *= p - 1;
}

Console.WriteLine(phi);
