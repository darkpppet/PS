using System;

string[] input = Console.ReadLine().Split(' ');

double h = double.Parse(input[0]);
double w = double.Parse(input[1]);
double n = double.Parse(input[2]);
double m = double.Parse(input[3]);

Console.WriteLine((int)Math.Ceiling(h / (n + 1)) * (int)Math.Ceiling(w / (m + 1)));
