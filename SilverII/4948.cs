using System;

while (true)
{
	int n = int.Parse(Console.ReadLine());
	
	if (n == 0)
		break;
	
	int count = 0;
	
	for (int i = 2 * n; i > n; i--)
	{
		if (i < 2)
			continue;

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
			count++;
	}
	
	Console.WriteLine(count);
}
