using System;
using System.Linq;

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

Console.WriteLine(arr.Count(x => x == 1) > arr.Count(x => x == 2) ? 1 : 2);
