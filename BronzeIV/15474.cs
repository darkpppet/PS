using System;

string[] input = Console.ReadLine().Split(' ');

double n = double.Parse(input[0]);
double a = double.Parse(input[1]);
int b = int.Parse(input[2]);
double c = double.Parse(input[3]);
int d = int.Parse(input[4]);

Console.WriteLine((int)Math.Ceiling(n / a) * b < (int)Math.Ceiling(n / c) * d ? (int)Math.Ceiling(n / a) * b : (int)Math.Ceiling(n / c) * d);
