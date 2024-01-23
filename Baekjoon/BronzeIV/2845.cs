using System;

string[] input = Console.ReadLine().Split(" ");

int num = int.Parse(input[0]) * int.Parse(input[1]);

int[] array = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

foreach (int i in array)
	Console.Write(i - num + " ");
