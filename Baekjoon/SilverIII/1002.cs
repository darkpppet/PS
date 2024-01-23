using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
	int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));
	
	int distance = (nums[0] - nums[3]) * (nums[0] - nums[3]) + (nums[1] - nums[4]) * (nums[1] - nums[4]);
	int rangeSum = (nums[2] + nums[5]) * (nums[2] + nums[5]);
	
	if (distance > rangeSum)
	{
		Console.WriteLine(0);
	}
	else if (distance == rangeSum)
	{
		Console.WriteLine(1);
	}
	else
	{
		int rangeDiff = (nums[2] - nums[5]) * (nums[2] - nums[5]);
		
		if (distance == 0 && rangeDiff == 0)
			Console.WriteLine(-1);
		else if (distance == rangeDiff)
			Console.WriteLine(1);
		else if (distance < rangeDiff)
			Console.WriteLine(0);
		else
			Console.WriteLine(2);
	}
}
