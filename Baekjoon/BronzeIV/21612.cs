using System;

int b = int.Parse(Console.ReadLine());

int p = 5 * b - 400;

Console.WriteLine(p);

if (p > 100)
	Console.WriteLine(-1);
else if (p < 100)
	Console.WriteLine(1);
else
	Console.WriteLine(0);
