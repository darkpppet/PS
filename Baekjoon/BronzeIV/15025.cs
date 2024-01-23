using System;

string[] input = Console.ReadLine().Split(' ');

int left = int.Parse(input[0]);
int right = int.Parse(input[1]);

if (left == right)
{
	if (left == 0)
		Console.WriteLine("Not a moose");
	else
		Console.WriteLine($"Even {left + right}");
}
else
{
	Console.WriteLine($"Odd {Math.Max(left, right) * 2}");
}
