using System;

int t = int.Parse(Console.ReadLine());

int a = t / 300;
t %= 300;

int b = t / 60;
t %= 60;

int c = t / 10;
t %= 10;

Console.WriteLine(t == 0 ? $"{a} {b} {c}" : -1);
