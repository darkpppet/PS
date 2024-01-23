using System;

char[] input = Console.ReadLine().ToCharArray();

int r = 0;

for (int i = 0; i < input.Length; i++)
	r = (r * 10 + (input[i] - '0')) % 2000_03_03;

Console.WriteLine(r);
