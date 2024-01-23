using System;

string[] input = Console.ReadLine().Split(" ");

double k = double.Parse(input[0]);
double w = double.Parse(input[1]);
double m = double.Parse(input[2]);

int hitCount = (int)Math.Ceiling((w - k) / m);

Console.WriteLine(hitCount < 0 ? 0 : hitCount);
