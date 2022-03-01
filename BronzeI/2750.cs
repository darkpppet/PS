using System;
using System.Collections.Generic;

int count = int.Parse(Console.ReadLine());

List<int> list = new();

for (int i = 0; i < count; i++)
	list.Add(int.Parse(Console.ReadLine()));

list.Sort();

foreach (int i in list)
	Console.WriteLine(i);
