using System;

string input = Console.ReadLine();

int x = int.Parse(input.Split(' ')[0]);
int y = int.Parse(input.Split(' ')[1]);
int w = int.Parse(input.Split(' ')[2]);
int h = int.Parse(input.Split(' ')[3]);

int min = int.MaxValue;

min = min < x ? min : x;
min = min < y ? min : y;
min = min < w - x ? min : w - x;
min = min < h - y ? min : h - y;

Console.WriteLine(min);
