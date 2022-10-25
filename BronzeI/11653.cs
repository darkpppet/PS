using System;

int n = int.Parse(Console.ReadLine());

int i = 2;

while (n > 1)
{
	if (n % i == 0)
	{
		Console.WriteLine(i);
		n /= i;		
	}
	else
	{
		i++;
	}
}
