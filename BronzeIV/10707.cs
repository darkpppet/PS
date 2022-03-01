using System;

int a = int.Parse(Console.ReadLine());
int b = int.Parse(Console.ReadLine());
int c = int.Parse(Console.ReadLine());
int d = int.Parse(Console.ReadLine());
int p = int.Parse(Console.ReadLine());

int x = p * a;
int y = b + (p > c ? p - c : 0) * d;

Console.WriteLine(x < y ? x : y);
