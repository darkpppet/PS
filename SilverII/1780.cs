using System;

int n = int.Parse(Console.ReadLine());
int[,] paper = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
	
	for (int j = 0; j < n; j++)
		paper[i, j] = row[j];
}

bool isAllSame(int startXIndex, int endXIndex, int startYIndex, int endYIndex)
{
	int num = paper[startXIndex, startYIndex];
	
	for (int i = startXIndex; i <= endXIndex; i++)
	{
		for (int j = startYIndex; j <= endYIndex; j++)
			if (paper[i, j] != num)
				return false;
	}
	
	return true;
}

int countM1 = 0;
int count0 = 0;
int count1 = 0;

void Calc(int startX, int endX, int startY, int endY)
{
	if (isAllSame(startX, endX, startY, endY))
	{
		switch (paper[startX, startY])
		{
			case -1:
				countM1++;
				break;
				
			case 0:
				count0++;
				break;
				
			case 1:
				count1++;
				break;
		}
	}
	else
	{
		int length = endX - startX;
		
		int newX1 = startX + length / 3;
		int newX2 = startX + 2 * length / 3;
		int newY1 = startY + length / 3;
		int newY2 = startY + 2 * length / 3;
		
		Calc(startX, newX1, startY, newY1);
		Calc(newX1 + 1, newX2, startY, newY1);
		Calc(newX2 + 1, endX, startY, newY1);
		
		Calc(startX, newX1, newY1 + 1, newY2);
		Calc(newX1 + 1, newX2, newY1 + 1, newY2);
		Calc(newX2 + 1, endX, newY1 + 1, newY2);
		
		Calc(startX, newX1, newY2 + 1, endY);
		Calc(newX1 + 1, newX2, newY2 + 1, endY);
		Calc(newX2 + 1, endX, newY2 + 1, endY);
	}
}

Calc(0, n - 1, 0, n - 1);

Console.WriteLine(countM1);
Console.WriteLine(count0);
Console.WriteLine(count1);
