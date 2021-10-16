using System;

int a = int.Parse(Console.ReadLine());
int x = int.Parse(Console.ReadLine());
int b = int.Parse(Console.ReadLine());
int y = int.Parse(Console.ReadLine());
int t = int.Parse(Console.ReadLine());

Console.WriteLine($"{a + 21 * (t - 30 < 0 ? 0 : t - 30) * x} {b + 21 * (t - 45 < 0 ? 0 : t - 45) * y}");
