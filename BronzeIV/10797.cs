using System;
using System.Linq;

int d = int.Parse(Console.ReadLine());
int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine(nums.Count(x => x == d));
