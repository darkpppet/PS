using System;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int h = int.Parse(input[1]);
int v = int.Parse(input[2]);

h = Math.Max(h, n - h);
v = Math.Max(v, n - v);

Console.WriteLine(4 * h * v);
