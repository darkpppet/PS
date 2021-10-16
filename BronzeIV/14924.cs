using System;

string[] input = Console.ReadLine().Split(" ");

int s = int.Parse(input[0]);
int t = int.Parse(input[1]);
int d = int.Parse(input[2]);

Console.WriteLine(t * d / (2 * s));
