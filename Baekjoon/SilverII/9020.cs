using System;
using System.Collections.Generic;

int count = int.Parse(Console.ReadLine());

List<int> primeList = new();

for (int i = 2; i < 10000; i++)
{
	bool isPrime = true;

	for (int j = 2; j <= Math.Sqrt(i); j++)
	{
		if (i % j == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
		primeList.Add(i);
}

for (int i = 0; i < count; i++)
{
	int n = int.Parse(Console.ReadLine());
	
	for (int j = n / 2; ; j--)
	{
		if (primeList.BinarySearch(j) >= 0 && primeList.BinarySearch(n - j) >= 0)
		{
			Console.WriteLine(j + " " + (n - j));
			break;
		}
	}
}
