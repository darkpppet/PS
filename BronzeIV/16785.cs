using System;

string[] input = Console.ReadLine().Split(' ');

int a = int.Parse(input[0]);
int b = int.Parse(input[1]);
int c = int.Parse(input[2]);

int day = 0;

day += 7 * (c / (7 * a + b));

c %= 7 * a + b;

day += Math.Min((int)Math.Ceiling((double)c / a), 7);

Console.WriteLine(day);
