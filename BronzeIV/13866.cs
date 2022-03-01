using System;
using System.Linq;

int[] levels = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] diffs = new int[3];

diffs[0] = Math.Abs(levels[0] + levels[1] - levels[2] - levels[3]);
diffs[1] = Math.Abs(levels[0] + levels[2] - levels[1] - levels[3]);
diffs[2] = Math.Abs(levels[0] + levels[3] - levels[1] - levels[2]);

Console.WriteLine(diffs.Min());
