using System;

int[] start = Array.ConvertAll(Console.ReadLine().Replace(" ", "").Split(':'), int.Parse);
int[] end = Array.ConvertAll(Console.ReadLine().Replace(" ", "").Split(':'), int.Parse);

int second = end[0] * 3600 + end[1] * 60 + end[2] - start[0] * 3600 - start[1] * 60 - start[2];

if (second < 0)
	second += 86400;

Console.WriteLine(second);
