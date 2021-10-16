using System;

int n = int.Parse(Console.ReadLine());

if (n % 2 == 0)
{
	if ((n / 2) % 2 == 0)
		Console.WriteLine("Even");
	else
		Console.WriteLine("Odd");
}
else
{
	Console.WriteLine("Either");
}
