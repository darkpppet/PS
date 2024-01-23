using System;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int w = int.Parse(input[1]);
int h = int.Parse(input[2]);
int l = int.Parse(input[3]);

int max = (w / l) * (h / l);

Console.WriteLine(n < max ? n : max);
