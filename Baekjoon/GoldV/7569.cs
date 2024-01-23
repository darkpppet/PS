using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int m = int.Parse(input[0]);
int n = int.Parse(input[1]);
int h = int.Parse(input[2]);

int[,,] box = new int[h, n, m];

for (int k = 0; k < h; k++)
{
	for (int j = 0; j < n; j++)
	{
		int[] inputLine = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
		
		for (int i = 0; i < m; i++)
			box[k, j, i] = inputLine[i];
	}
}

List<(int Xpos, int Ypos, int Zpos)> beforeRiped = new();

for (int k = 0; k < h; k++)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (box[k, j, i] == 1)
				beforeRiped.Add((i, j, k));
		}
	}
}

int day = -1;

do
{
	List<(int Xpos, int Ypos, int Zpos)> tempList = new();
	
	foreach ((int Xpos, int Ypos, int Zpos) in beforeRiped)
	{
		if (Zpos - 1 >= 0 && box[Zpos - 1, Ypos, Xpos] == 0)
		{
			box[Zpos - 1, Ypos, Xpos] = 1;
			tempList.Add((Xpos, Ypos, Zpos - 1));
		}
		
		if (Zpos + 1 < h && box[Zpos + 1, Ypos, Xpos] == 0)
		{
			box[Zpos + 1, Ypos, Xpos] = 1;
			tempList.Add((Xpos, Ypos, Zpos + 1));
		}
		
		if (Ypos - 1 >= 0 && box[Zpos, Ypos - 1, Xpos] == 0)
		{
			box[Zpos, Ypos - 1, Xpos] = 1;
			tempList.Add((Xpos, Ypos - 1, Zpos));
		}
		
		if (Ypos + 1 < n && box[Zpos, Ypos + 1, Xpos] == 0)
		{
			box[Zpos, Ypos + 1, Xpos] = 1;
			tempList.Add((Xpos, Ypos + 1, Zpos));
		}
		
		if (Xpos - 1 >= 0 && box[Zpos, Ypos, Xpos - 1] == 0)
		{
			box[Zpos, Ypos, Xpos - 1] = 1;
			tempList.Add((Xpos - 1, Ypos, Zpos));
		}
		
		if (Xpos + 1 < m && box[Zpos, Ypos, Xpos + 1] == 0)
		{
			box[Zpos, Ypos, Xpos + 1] = 1;
			tempList.Add((Xpos + 1, Ypos, Zpos));
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
