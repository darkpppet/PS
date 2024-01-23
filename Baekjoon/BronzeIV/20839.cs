using System;

string[] input = Console.ReadLine().Split(' ');

double x = double.Parse(input[0]);
double y = double.Parse(input[1]);
double z = double.Parse(input[2]);

input = Console.ReadLine().Split(' ');

double xp = double.Parse(input[0]);
double yp = double.Parse(input[1]);
double zp = double.Parse(input[2]);

if (xp == x && yp == y && zp == z)
	Console.WriteLine("A");
else if (yp == y && zp == z && xp >= (x / 2))
	Console.WriteLine("B");
else if (yp == y && zp == z)
	Console.WriteLine("C");
else if (zp == z && yp >= (y / 2))
	Console.WriteLine("D");
else if (zp == z)
	Console.WriteLine("E");
