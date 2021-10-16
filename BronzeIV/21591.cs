using System;

string[] input = Console.ReadLine().Split(' ');

int wc = int.Parse(input[0]);
int hc = int.Parse(input[1]);
int ws = int.Parse(input[2]);
int hs = int.Parse(input[3]);

if (wc - ws >= 2 && hc - hs >= 2)
	Console.WriteLine(1);
else
	Console.WriteLine(0);
