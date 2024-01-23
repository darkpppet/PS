using System;

int t = int.Parse(Console.ReadLine());

int[] factorial = { 1, 1, 2, 6, 24, 120, 720, 5_040, 40_320, 362_880, 3_628_800 };

for (int i = 0; i < t; i++)
{
	int n = int.Parse(Console.ReadLine());
	
	int count = 0;
	
	for (int count3 = 0; count3 * 3 <= n; count3++)
	{
		for (int count2 = 0; count2 * 2 <= n - count3 * 3; count2++)
		{
			int count1 = n - count3 * 3 - count2 * 2;
			
			count += factorial[count1 + count2 + count3] / (factorial[count1] * factorial[count2] * factorial[count3]);
		}
	}
	
	Console.WriteLine(count);
}
