using System;

string[] input = Console.ReadLine().Split(" ");

long n = long.Parse(input[0]);
long m = long.Parse(input[1]);

Console.WriteLine(Math.Abs(n - m));
