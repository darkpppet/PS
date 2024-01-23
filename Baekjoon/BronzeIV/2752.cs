using System;

int[] arr = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
Array.Sort(arr);

foreach (int i in arr)
	Console.Write($"{i} ");
