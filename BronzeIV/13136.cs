using System;

string[] input = Console.ReadLine().Split(' ');

double r = double.Parse(input[0]);
double c = double.Parse(input[1]);
double n = double.Parse(input[2]);

Console.WriteLine(Math.Ceiling(r / n) * Math.Ceiling(c / n));
