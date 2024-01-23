using System;

string[] input = Console.ReadLine().Split(" ");

int h = int.Parse(input[0]);
int m = int.Parse(input[1]);
int s = int.Parse(input[2]);

int t = int.Parse(Console.ReadLine());

int th = t / 3600;
int tm = (t - 3600 * th) / 60;
int ts = t % 60;

s += ts;
m += tm + s / 60;
h += th + m / 60;

Console.WriteLine($"{h % 24} {m % 60} {s % 60}"); 
