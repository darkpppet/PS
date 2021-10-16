using System;

string[] input = Console.ReadLine().Split(" ");

int d = int.Parse(input[0]) - 11;
int h = int.Parse(input[1]) - 11;
int m = int.Parse(input[2]) - 11;

int total = (d * 24 + h) * 60 + m;

Console.WriteLine(total < 0 ? -1 : total);
