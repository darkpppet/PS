using System;

string[] input = Console.ReadLine().Split(' ');

int t1 = int.Parse(input[0]);
int v1 = int.Parse(input[1]);

input = Console.ReadLine().Split(' ');

int t2 = int.Parse(input[0]);
int v2 = int.Parse(input[1]);

if (t2 < 0 && v2 >= 10)
	Console.WriteLine("A storm warning for tomorrow! Be careful and stay home if possible!");
else if (t2 < t1)
	Console.WriteLine("MCHS warns! Low temperature is expected tomorrow.");
else if (v2 > v1)
	Console.WriteLine("MCHS warns! Strong wind is expected tomorrow.");
else
	Console.WriteLine("No message");
