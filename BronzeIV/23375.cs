using System;

string[] input = Console.ReadLine().Split(' ');

int x = int.Parse(input[0]);
int y = int.Parse(input[1]);

int r = int.Parse(Console.ReadLine());

Console.WriteLine($"{x - r} {y + r}");
Console.WriteLine($"{x + r} {y + r}");
Console.WriteLine($"{x + r} {y - r}");
Console.WriteLine($"{x - r} {y - r}");
