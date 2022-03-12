using System;

string[] input = Console.ReadLine().Split(' ');

double t = double.Parse(input[0]);
double p = double.Parse(input[1]);

Console.WriteLine(p < 20 ? 2 * p * t / (120 - 2 * p) : (p + 20) * t / (100 - p));
