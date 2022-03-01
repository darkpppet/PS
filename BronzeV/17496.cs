using System;

int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine(((nums[0] - 1) / nums[1]) * nums[2] * nums[3]);
