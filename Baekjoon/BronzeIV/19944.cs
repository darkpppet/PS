using System;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

if (m == 1 || m == 2)
	Console.WriteLine("NEWBIE!");
else if (m <= n)
	Console.WriteLine("OLDBIE!");
else
	Console.WriteLine("TLE!");
