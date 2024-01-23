using System;

int[] origin = { 1, 1, 2, 2, 2, 8 };
int[] input = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

for (int i = 0; i < 6; i++)
	Console.Write(origin[i] - input[i] + " ");
