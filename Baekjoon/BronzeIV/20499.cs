using System;

string[] input = Console.ReadLine().Split("/");

int k = int.Parse(input[0]);
int d = int.Parse(input[1]);
int a = int.Parse(input[2]);

Console.WriteLine(k + a < d || d == 0 ? "hasu" : "gosu");
