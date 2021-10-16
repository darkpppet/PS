using System;

string[] input = Console.ReadLine().Split(" ");

int x = int.Parse(input[0]);
int k = int.Parse(input[1]);

if (7 * k <= x)
	Console.WriteLine(k * 7000);
else if (7 * k <= 2 * x)
	Console.WriteLine(k * 3500);
else if (7 * k <= 4 * x)
	Console.WriteLine(k * 1750);
else
	Console.WriteLine(0);
