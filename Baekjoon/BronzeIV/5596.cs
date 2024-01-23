using System;
using System.Linq;

int[] arr1 = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] arr2 = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine(Math.Max(arr1.Sum(), arr2.Sum()));
