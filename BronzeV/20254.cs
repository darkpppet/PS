using System;

int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

System.Console.WriteLine(56 * nums[0] + 24 * nums[1] + 14 * nums[2] + 6 * nums[3]);
