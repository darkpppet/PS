using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<int> list = new(Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x)));

list.Sort();

int sum = 0;

for (int i = 0; i < n; i++)
	sum += (n - i) * list[i];

Console.WriteLine(sum);
