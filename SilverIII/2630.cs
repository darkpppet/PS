using System;

int n = int.Parse(Console.ReadLine());

int[,] inputPaper = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] input = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));
	
	for (int j = 0; j < n; j++)
		inputPaper[i, j] = input[j];
}

int whiteCount = 0;
int blueCount = 0;

void CutPaper(int[,] paper, int length)
{
	bool isOneColor = true;
	
	foreach (int color in paper)
	{
		if (color != paper[0, 0])
			isOneColor = false;
	}
	
	if (length == 1 || isOneColor)
	{
		if (paper[0, 0] == 0)
			whiteCount++;
		else
			blueCount++;
	}
	else
	{
		int[,] paperPiece1 = new int[length / 2, length / 2];
		int[,] paperPiece2 = new int[length / 2, length / 2];
		int[,] paperPiece3 = new int[length / 2, length / 2];
		int[,] paperPiece4 = new int[length / 2, length / 2];
		
		for (int i = 0; i < length / 2; i++)
		{
			for (int j = 0; j < length / 2; j++)
			{
				paperPiece1[i, j] = paper[i, j];
				paperPiece2[i, j] = paper[i + length / 2, j];
				paperPiece3[i, j] = paper[i, j + length / 2];
				paperPiece4[i, j] = paper[i + length / 2, j + length / 2];
			}
		}
		
		CutPaper(paperPiece1, length / 2);
		CutPaper(paperPiece2, length / 2);
		CutPaper(paperPiece3, length / 2);
		CutPaper(paperPiece4, length / 2);
	}
}

CutPaper(inputPaper, n);

Console.WriteLine(whiteCount);
Console.WriteLine(blueCount);
