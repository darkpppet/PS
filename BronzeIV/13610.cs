using System;

string[] input = Console.ReadLine().Split(' ');

int x = int.Parse(input[0]);
int y = int.Parse(input[1]);

double n = 1;

for (; Math.Floor(n * y / x) <= n; n++);

Console.WriteLine((int)(n + 1));
