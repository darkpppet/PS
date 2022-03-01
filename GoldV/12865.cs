using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
int k = int.Parse(input[1]);

List<(int Weight, int Value)> stuffList = new();

for (int i = 0; i < n; i++)
{
	input = Console.ReadLine().Split(' ');
	stuffList.Add((int.Parse(input[0]), int.Parse(input[1])));
}

int[,] table = new int[n, k + 1];

for (int j = stuffList[0].Weight; j <= k; j++)
	table[0, j] = stuffList[0].Value;

for (int i = 1; i < n; i++)
{
	for (int j = 1; j < stuffList[i].Weight && j <= k; j++)
		table[i, j] = table[i - 1, j];
	
	for (int j = stuffList[i].Weight; j <= k; j++)
		table[i, j] = Math.Max(table[i - 1, j], table[i - 1, j - stuffList[i].Weight] + stuffList[i].Value);
}

Console.WriteLine($"{table[n - 1, k]}");
