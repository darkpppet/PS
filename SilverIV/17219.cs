using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

Dictionary<string, string> dictionary = new();

for (int i = 0; i < n; i++)
{
	input = Console.ReadLine().Split(" ");
	dictionary[input[0]] = input[1];
}

for (int i = 0; i < m; i++)
	Console.WriteLine(dictionary[Console.ReadLine()]);
