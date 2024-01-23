using System;

string[] input = Console.ReadLine().Split(' ');

long a = long.Parse(input[0]);
long b = long.Parse(input[1]);

Console.WriteLine(a < b ? a + 1 : b);
