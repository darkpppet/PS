using System;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	int n = int.Parse(Console.ReadLine());
	
	int[,] sticker = new int[2, n];
	
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
		sticker[0, j] = row[j];
	
	row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
		sticker[1, j] = row[j];
	
	(int Score, int LastIndex)[] maxSum = new (int Score, int LastIndex)[n];
	
	if (sticker[0, 0] == sticker[1, 0])
		maxSum[0] = (sticker[0, 0], -1);
	else if (sticker[0, 0] < sticker[1, 0])
		maxSum[0] = (sticker[1, 0], 1);
	else
		maxSum[0] = (sticker[0, 0], 0);
	
	if (sticker[0, 1] + sticker[1, 0] == sticker[1, 1] + sticker[0, 0])
		maxSum[1] = (sticker[0, 1] + sticker[1, 0], -1);
	else if (sticker[0, 1] + sticker[1, 0] < sticker[1, 1] + sticker[0, 0])
		maxSum[1] = (sticker[1, 1] + sticker[0, 0], 1);
	else
		maxSum[1] = (sticker[0, 1] + sticker[1, 0], 0);
	
	for (int j = 2; j < n; j++)
	{
		if (maxSum[j - 1].LastIndex == -1)
		{
			if (sticker[0, j] == sticker[1, j])
				maxSum[j] = (maxSum[j - 1].Score + sticker[0, j], -1);
			else if (sticker[0, j] < sticker[1, j])
				maxSum[j] = (maxSum[j - 1].Score + sticker[1, j], 1);
			else
				maxSum[j] = (maxSum[j - 1].Score + sticker[0, j], 0);
		}
		else if (maxSum[j - 2].LastIndex == -1)
		{
			if (sticker[0, j] + sticker[1, j - 1] == sticker[1, j] + sticker[0, j - 1])
				maxSum[j] = (maxSum[j - 2].Score + sticker[0, j] + sticker[1, j - 1], -1);
			else if (sticker[0, j] + sticker[1, j - 1] < sticker[1, j] + sticker[0, j - 1])
				maxSum[j] = (maxSum[j - 2].Score + sticker[1, j] + sticker[0, j - 1], 1);
			else
				maxSum[j] = (maxSum[j - 2].Score + sticker[0, j] + sticker[1, j - 1], 0);
		}
		else
		{
			(int Score, int LastIndex) max1;
			
			if (maxSum[j - 1].LastIndex == 1)
				max1 = (maxSum[j - 1].Score + sticker[0, j], 0);
			else
				max1 = (maxSum[j - 1].Score + sticker[1, j], 1);
			
			(int Score, int LastIndex) max2;
			
			if (maxSum[j - 2].LastIndex == 1)
				max2 = (maxSum[j - 2].Score + sticker[0, j], 0);
			else
				max2 = (maxSum[j - 2].Score + sticker[1, j], 1);
			
			if (max1.Score == max2.Score)
				maxSum[j] = (max1.Score, -1);
			else
				maxSum[j] = max1.Score > max2.Score ? max1 : max2;
		}
	}
	
	Console.WriteLine(maxSum[^1].Score);
}
