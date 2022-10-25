using System;

string[] input = Console.ReadLine().Split(" ");

int h = int.Parse(input[0]);
int m = int.Parse(input[1]);

int t = int.Parse(Console.ReadLine());

m += t % 60;
h += t / 60 + m / 60;

Console.WriteLine(h % 24 + " " + m % 60); 
