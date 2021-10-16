using System;

string[] input = Console.ReadLine().Split(' ');

int p1 = int.Parse(input[0]);
int s1 = int.Parse(input[1]);

input = Console.ReadLine().Split(' ');

int s2 = int.Parse(input[0]);
int p2 = int.Parse(input[1]);

if (p1 + p2 == s1 + s2)
{
	if (s1 == p2)
		Console.WriteLine("Penalty");
	else
		Console.WriteLine(p2 > s1 ? "Persepolis" : "Esteghlal");
}
else
{
	Console.WriteLine(p1 + p2 > s1 + s2 ? "Persepolis" : "Esteghlal");
}
