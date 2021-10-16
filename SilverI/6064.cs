using System;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int m = int.Parse(input[0]);
	int n = int.Parse(input[1]);
	int x = int.Parse(input[2]) % m;
	int y = int.Parse(input[3]) % n;
	
	int result = -1;
	
	for (int k = 0; k < n; k++)
	{
		if ((m * k + x) % n == y)
		{
			result = m * k + x;
			break;
		}
	}
	
	if (result == 0)
	{
		for (int k = 1; k < n; k++)
		{
			if (m * k % n == 0)
			{
				result = m * k;
				break;
			}
		}
	}
	
	Console.WriteLine(result);
}
