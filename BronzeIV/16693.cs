using System;

string[] input = Console.ReadLine().Split(' ');

double a1 = double.Parse(input[0]);
double p1 = double.Parse(input[1]);

input = Console.ReadLine().Split(' ');

double r1 = double.Parse(input[0]);
double p2 = double.Parse(input[1]);

Console.WriteLine(Math.PI * r1 * r1 / p2 > a1 / p1 ? "Whole pizza" : "Slice of pizza");
