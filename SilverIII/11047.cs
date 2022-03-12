using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int k = int.Parse(input[1]);

List<int> list = new();

for (int i = 0; i < n; i++)
	list.Add(int.Parse(Console.ReadLine()));

int count = 0;

for (int i = 1; i <= n; i++)
{
	count += k / list[^i];
	k %= list[^i];
}

Console.WriteLine(count);
