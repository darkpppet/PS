using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int> measures = new();

int sqrt = (int)Math.Sqrt(n);

for (int i = 1; i <= sqrt; i++)
{
	if (n % i == 0)
	{
		measures.Add(i);
		measures.Add(n / i);
	}
}

bool isFound = false;

foreach (int measure in measures)
{
	HashSet<int> primeFactors = new();
	
	int tempMeasure = measure;
	
	int phi = measure;

	int measureSqrt = (int)Math.Sqrt(measure);

	for (int i = 2; tempMeasure > 1 && i <= measureSqrt; i++)
	{
		if (tempMeasure % i == 0)
		{
			tempMeasure /= i;
			primeFactors.Add(i);
			i--;
		}
	}

	if (tempMeasure != 1)
	{
		phi /= tempMeasure;
		phi *= tempMeasure - 1;
	}

	foreach (int p in primeFactors)
	{
		phi /= p;
		phi *= p - 1;
	}
	
	if (measure * phi == n)
	{
		Console.WriteLine(measure);
		isFound = true;
		break;
	}
}

if (!isFound)
	Console.WriteLine(-1);
