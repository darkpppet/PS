using System;

ulong PowMod(ulong a, ulong exp, ulong n)
{
	if (exp == 0)
		return 1;
	
	if (exp == 1)
		return a % n;
	
	ulong sqrt = PowMod(a, exp / 2, n);
	
	if (exp % 2 == 0)
		return (sqrt * sqrt) % n;
	else
		return (((sqrt * sqrt) % n) * a) % n;
}

ulong Pow(ulong a, ulong exp)
{
	if (exp == 0)
		return 1;
	
	if (exp == 1)
		return a;
	
	ulong sqrt = Pow(a, exp / 2);
	
	if (exp % 2 == 0)
		return sqrt * sqrt;
	else
		return sqrt * sqrt * a;
}

int testCount = int.Parse(Console.ReadLine());

int count = 0;

for (int t = 0; t < testCount; t++)
{
	ulong n = 2 * ulong.Parse(Console.ReadLine()) + 1;
	
	ulong nMinus1 = n - 1;
	ulong s = 0;
	
	for (; nMinus1 % 2 == 0; nMinus1 /= 2, s++);
	
	ulong d = nMinus1;
	
	bool isPrime = false;
	
	ulong a = 2;
	
	if (PowMod(a, d, n) == 1)
		isPrime = true;
	
	for (ulong r = 0; !isPrime && r <= s - 1; r++)
	{
		if (PowMod(a, d * Pow(2, r), n) == n - 1)
			isPrime = true;
	}
	
	if (n > 7 && isPrime)
	{
		bool isPrime7 = false;
		
		a = 7;
		
		if (PowMod(a, d, n) == 1)
			isPrime7 = true;
		
		for (ulong r = 0; !isPrime7 && r <= s - 1; r++)
		{
			if (PowMod(a, d * Pow(2, r), n) == n - 1)
				isPrime7 = true;
		}
		
		isPrime = isPrime && isPrime7;
	}
	
	if (n > 61 && isPrime)
	{
		bool isPrime61 = false;
		
		a = 61;
		
		if (PowMod(a, d, n) == 1)
			isPrime61 = true;
		
		for (ulong r = 0; !isPrime61 && r <= s - 1; r++)
		{
			if (PowMod(a, d * Pow(2, r), n) == n - 1)
				isPrime61 = true;
		}
		
		isPrime = isPrime && isPrime61;
	}
	
	if (isPrime)
		count++;
}

Console.WriteLine(count);
