using System;
using System.Linq;

int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine(nums.Sum() * 5);
