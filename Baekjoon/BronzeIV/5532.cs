using System;

int l = int.Parse(Console.ReadLine());
double a = double.Parse(Console.ReadLine());
double b = double.Parse(Console.ReadLine());
double c = double.Parse(Console.ReadLine());
double d = double.Parse(Console.ReadLine());

Console.WriteLine($"{l - (int)Math.Max(Math.Ceiling(a / c), Math.Ceiling(b / d))}");
