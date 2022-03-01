using System;

string[] input = Console.ReadLine().Split(" ");

double l = double.Parse(input[0]);
double h = double.Parse(input[1]);
double w = double.Parse(input[2]);

double k = l / Math.Sqrt(h * h + w * w);

Console.WriteLine((int)(h * k) + " " + (int)(w * k));
