using System;

int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
Array.Sort(arr);

Console.WriteLine(arr[1]);
