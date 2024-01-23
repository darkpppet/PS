using System;

int a = int.Parse(Console.ReadLine());
int b = int.Parse(Console.ReadLine());
int c = int.Parse(Console.ReadLine());
int d = int.Parse(Console.ReadLine());
int e = int.Parse(Console.ReadLine());

Console.WriteLine(a < 0 ? -1 * a * c + d + b * e : (b - a) * e);
