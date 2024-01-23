using System;
using System.Linq;

int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

int score = 0;

if (nums[0] == nums[1] && nums[1] == nums[2])
	score = 10000 + nums[0] * 1000;
else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0])
	score = 1000 + (nums[0] == nums[1] ? nums[0] : nums[2]) * 100;
else
	score = nums.Max() * 100;

Console.WriteLine(score);
