using System;

int[] a = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] c = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine((c[0] - a[2]) + " " + (c[1] / a[1]) + " " + (c[2] - a[0]));
