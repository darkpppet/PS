using System;

int testCount = int.Parse(Console.ReadLine());

for (int t = 0; t < testCount; t++)
{
	string[] input = Console.ReadLine().Split(" ");

	int m = int.Parse(input[0]);
	int n = int.Parse(input[1]);
	int k = int.Parse(input[2]);

	int[,] field = new int[n, m];

	for (int i = 0; i < k; i++)
	{
		input = Console.ReadLine().Split(" ");

		int x = int.Parse(input[0]);
		int y = int.Parse(input[1]);

		field[y, x] = 1;
	}

	int[,] bugged = new int[n, m];

	void Bugging(int i, int j)
	{
		if (field[i, j] == 1 && bugged[i, j] == 0)
		{
			bugged[i, j] = 1;

			if (i - 1 >= 0)
				Bugging(i - 1, j);

			if (i + 1 < n)
				Bugging(i + 1, j);

			if (j - 1 >= 0)
				Bugging(i, j - 1);

			if (j + 1 < m)
				Bugging(i, j + 1);
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i, j] == 1 && bugged[i, j] == 0)
			{
				Bugging(i, j);
				count++;
			}
		}
	}
	
	Console.WriteLine(count);
}
