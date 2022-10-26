using System;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);
int k = int.Parse(input[2]);

Console.WriteLine(m / k > 0 ? (m / k + k - 1) * n : m * n);
