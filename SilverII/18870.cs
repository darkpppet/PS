using System;
using System.Text;
using System.Collections.Generic;

Console.ReadLine();

int[] poses = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));
List<int> sortedSet = new(new SortedSet<int>(poses));

StringBuilder outputBuilder = new();

foreach (int pos in poses)
	outputBuilder.Append(sortedSet.BinarySearch(pos) + " ");

Console.WriteLine(outputBuilder.ToString());
