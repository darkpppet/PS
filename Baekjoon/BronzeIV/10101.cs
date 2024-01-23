using System;

int a = int.Parse(Console.ReadLine());
int b = int.Parse(Console.ReadLine());
int c = int.Parse(Console.ReadLine());

if (a + b + c != 180)
{
	Console.WriteLine("Error");
}
else
{
	if (a == b && b == c)
		Console.WriteLine("Equilateral");
	else if (a != b && b != c && c != a)
		Console.WriteLine("Scalene");
	else
		Console.WriteLine("Isosceles");
}
