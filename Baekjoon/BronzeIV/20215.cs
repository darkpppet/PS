using System;

string[] input = Console.ReadLine().Split(' ');

double w = double.Parse(input[0]);
double h = double.Parse(input[1]);

Console.WriteLine(w + h - Math.Sqrt(w * w + h * h));
