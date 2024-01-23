using System;

string[] input = Console.ReadLine().Split(" ");

int k = int.Parse(input[0]);
int n = int.Parse(input[1]);
int m = int.Parse(input[2]);

int need = n * k - m;

Console.WriteLine(need < 0 ? 0 : need);
