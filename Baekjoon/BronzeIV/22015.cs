using System;
using System.Linq;

int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

Console.WriteLine(input.Max() * 3 - input.Sum());
