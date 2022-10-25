using System;
using System.Text;

int n = int.Parse(Console.ReadLine());

int[,] image = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().ToCharArray(), x => x - '0');
	
	for (int j = 0; j < n; j++)
		image[i, j] = row[j];
}

bool IsOneColor(int xStart, int xEnd, int yStart, int yEnd)
{
	int color = image[xStart, yStart];
	
	for (int i = xStart; i <= xEnd; i++)
	{
		for (int j = yStart; j <= yEnd; j++)
		{
			if (image[i, j] != color)
				return false;
		}
	}
	
	return true;
}

StringBuilder outputBuilder = new();

void Compress(int xStart, int xEnd, int yStart, int yEnd)
{
	if (IsOneColor(xStart, xEnd, yStart, yEnd))
	{
		outputBuilder.Append(image[xStart, yStart]);
	}
	else
	{
		outputBuilder.Append("(");
		
		int length = xEnd - xStart;
		int newXStart = xEnd - length / 2;
		int newXEnd = xStart + length / 2;
		int newYStart = yEnd - length / 2;
		int newYEnd = yStart + length / 2;
		
		Compress(xStart, newXEnd, yStart, newYEnd);
		Compress(xStart, newXEnd, newYStart, yEnd);
		Compress(newXStart, xEnd, yStart, newYEnd);
		Compress(newXStart, xEnd, newYStart, yEnd);
	
		outputBuilder.Append(")");
	}
}

Compress(0, n - 1, 0, n - 1);

Console.WriteLine(outputBuilder.ToString());
