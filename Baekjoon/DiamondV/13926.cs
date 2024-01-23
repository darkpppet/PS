using System;
using System.Collections.Generic;

HashSet<int> hashSet = new();

long n = long.Parse(Console.ReadLine());
double phi = n;

for (int i = 2; n > 1; i++)
{
	if (n % i == 0)
	{
		n /= i;
		hashSet.Add(i);
		i--;
	}
}

foreach (int p in hashSet)
	phi = phi * (p - 1) / p;

Console.WriteLine((long)phi);
