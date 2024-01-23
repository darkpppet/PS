using System;
using System.Linq;

string[] input = Console.ReadLine().Split(' ');

double h = double.Parse(input[0]);
double w = double.Parse(input[1]);

Console.WriteLine(new[] { Math.Min(h / 2, w / 2), Math.Min(h, w / 3) , Math.Min(w , h / 3) }.Max());
