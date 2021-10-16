using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int m = int.Parse(input[0]);
int n = int.Parse(input[1]);

int[,] box = new int[n, m];

for (int i = 0; i < n; i++)
{
	int[] inputLine = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));
	
	for (int j = 0; j < m; j++)
		box[i, j] = inputLine[j];
}

List<(int, int)> beforeRiped = new();

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		if (box[i, j] == 1)
			beforeRiped.Add((i, j));
	}
}

int day = -1;

do
{
	List<(int, int)> tempList = new();
	
	foreach ((int i, int j) in beforeRiped)
	{
		if (i - 1 >= 0 && box[i - 1, j] == 0)
		{
			box[i - 1, j] = 1;
			tempList.Add((i - 1, j));
		}
			
		if (i + 1 < n && box[i + 1, j] == 0)
		{
			box[i + 1, j] = 1;
			tempList.Add((i + 1, j));
		}
		
		if (j - 1 >= 0 && box[i, j - 1] == 0)
		{
			box[i, j - 1] = 1;
			tempList.Add((i, j - 1));
		}
			
		if (j + 1 < m && box[i, j + 1] == 0)
		{
			box[i, j + 1] = 1;
			tempList.Add((i, j + 1));
		}
	}
	
	beforeRiped = new(tempList);
	
	day++;
} while (beforeRiped.Count > 0);

bool isAllRiped = true;

foreach (int i in box)
{
	if (i == 0)
	{
		isAllRiped = false;
		break;
	}
}

Console.WriteLine(isAllRiped ? day : -1);
