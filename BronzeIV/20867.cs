using System;

string[] input = Console.ReadLine().Split(' ');

double m = double.Parse(input[0]);
double s = double.Parse(input[1]);
double g = double.Parse(input[2]);

input = Console.ReadLine().Split(' ');

double a = double.Parse(input[0]);
double b = double.Parse(input[1]);

input = Console.ReadLine().Split(' ');

double l = double.Parse(input[0]);
double r = double.Parse(input[1]);

double leftTime = l / a + m / g;
double rightTime = r / b + m / s;

Console.WriteLine(leftTime > rightTime ? "latmask" : "friskus");
