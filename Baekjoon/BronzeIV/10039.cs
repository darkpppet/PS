using System;
using System.Collections.Generic;
using System.Linq;

List<int> list = new();

for (int i = 0; i < 5; i++)
{
	int n = int.Parse(Console.ReadLine());
	list.Add(n > 40 ? n : 40);
}

Console.WriteLine(list.Average());
