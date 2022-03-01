using System;

string[] input = Console.ReadLine().Split(' ');

double a = double.Parse(input[0]);
double p = double.Parse(input[1]);

if (a * 7 == p * 13)
	Console.WriteLine("lika");
else
	Console.WriteLine(a * 7 > p * 13 ? "Axel" : "Petra");
