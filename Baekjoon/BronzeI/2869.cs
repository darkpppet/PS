using System;

string input = Console.ReadLine();

int a = int.Parse(input.Split(" ")[0]);
int b = int.Parse(input.Split(" ")[1]);
int v = int.Parse(input.Split(" ")[2]);

Console.WriteLine(Math.Ceiling((double)(v - a) / (double)(a - b)) + 1);
