using System;

int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

System.Console.WriteLine((((nums[0] + 1) * (nums[1] + 1)) / (nums[2] + 1)) - 1);
