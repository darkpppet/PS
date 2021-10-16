using System;

string[] input = Console.ReadLine().Split(" ");

int expN = (int)Math.Pow(2, int.Parse(input[0]));
int r = int.Parse(input[1]);
int c = int.Parse(input[2]);

int count = 0;

void MakeMap(int xStart, int xEnd, int yStart, int yEnd)
{
	if (xStart == xEnd && yStart == yEnd)
	{
		if (xStart == c && yStart == r)
			Console.WriteLine(count);
		
		return;
	}
	
	if (yStart <= r && r <= (yStart + yEnd) / 2)
	{
		if (xStart <= c && c <= (xStart + xEnd) / 2)
		{
			MakeMap(xStart, (xStart + xEnd) / 2, yStart, (yStart + yEnd) / 2);
		}
		else
		{
			count += ((xEnd - xStart + 1) / 2) * ((xEnd - xStart + 1) / 2);
			MakeMap((xStart + xEnd) / 2 + 1, xEnd, yStart, (yStart + yEnd) / 2);
		}
	}
	else
	{
		if (xStart <= c && c <= (xStart + xEnd) / 2)
		{
			count += ((xEnd - xStart + 1) / 2) * ((xEnd - xStart + 1) / 2) * 2;
			MakeMap(xStart, (xStart + xEnd) / 2, (yStart + yEnd) / 2 + 1, yEnd);
		}
		else
		{
			count += ((xEnd - xStart + 1) / 2) * ((xEnd - xStart + 1) / 2) * 3;
			MakeMap((xStart + xEnd) / 2 + 1, xEnd, (yStart + yEnd) / 2 + 1, yEnd);
		}
	}
}

MakeMap(0, expN - 1, 0, expN - 1);
