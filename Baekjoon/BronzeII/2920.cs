using System;
using System.Linq;

int[] ascending = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
int[] descending = new int[] { 8, 7, 6, 5, 4, 3, 2, 1 };

int[] numbers = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

if (numbers.SequenceEqual(ascending))
    Console.WriteLine("ascending");
else if (numbers.SequenceEqual(descending))
    Console.WriteLine("descending");
else
    Console.WriteLine("mixed");
