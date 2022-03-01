using System;

int n = int.Parse(Console.ReadLine());

int[,] nums = new int[n, 3];

for (int i = 0; i < n; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	nums[i, 0] = int.Parse(input[0]);
	nums[i, 1] = int.Parse(input[1]);
	nums[i, 2] = int.Parse(input[2]);
}

(int, int, int) tempMaxSum = (nums[n - 1, 0], nums[n - 1, 1], nums[n - 1, 2]);
(int, int, int) tempMinSum = (nums[n - 1, 0], nums[n - 1, 1], nums[n - 1, 2]);

for (int i = n - 2; i >= 0; i--)
{
	int i1 = Math.Max(tempMaxSum.Item1, tempMaxSum.Item2);
	int i3 = Math.Max(tempMaxSum.Item2, tempMaxSum.Item3);
	int i2 = Math.Max(i1, i3);
	
	tempMaxSum = (nums[i, 0] + i1, nums[i, 1] + i2, nums[i, 2] + i3);
	
	i1 = Math.Min(tempMinSum.Item1, tempMinSum.Item2);
	i3 = Math.Min(tempMinSum.Item2, tempMinSum.Item3);
	i2 = Math.Min(i1, i3);
	
	tempMinSum = (nums[i, 0] + i1, nums[i, 1] + i2, nums[i, 2] + i3);
}

int max = Math.Max(Math.Max(tempMaxSum.Item1, tempMaxSum.Item2), tempMaxSum.Item3);
int min = Math.Min(Math.Min(tempMinSum.Item1, tempMinSum.Item2), tempMinSum.Item3);

Console.WriteLine($"{max} {min}");
