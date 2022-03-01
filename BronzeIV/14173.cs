using System;

int[] pasture1 = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
int[] pasture2 = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

int width = Math.Max(pasture1[2], pasture2[2]) - Math.Min(pasture1[0], pasture2[0]);
int height = Math.Max(pasture1[3], pasture2[3]) - Math.Min(pasture1[1], pasture2[1]);

int length = Math.Max(width, height);

Console.WriteLine(length * length);
