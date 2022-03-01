using System;

int m = int.Parse(Console.ReadLine());
int d = int.Parse(Console.ReadLine());

if (m == 2)
{
	if (d == 18)
		Console.WriteLine("Special");
	else
		Console.WriteLine(d < 18 ? "Before" : "After");
}
else
{
	Console.WriteLine(m < 2 ? "Before" : "After");
}
