using System;

int m = int.Parse(Console.ReadLine());
int n = int.Parse(Console.ReadLine());

int sum = 0;
int min = 0;

for (int i = n; i >= m; i--)
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
	{
		sum += i;
		min = i;
	}
}

if (sum == 0)
{
	Console.WriteLine(-1);
}
else
{
	Console.WriteLine(sum);
	Console.WriteLine(min);
}	
