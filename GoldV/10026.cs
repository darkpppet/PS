using System;

int n = int.Parse(Console.ReadLine());

char[,] screen = new char[n, n];
char[,] screenForBlind = new char[n, n];

for (int i = 0; i < n; i++)
{
	char[] row = Console.ReadLine().ToCharArray();
	
	for (int j = 0; j < n; j++)
	{
		screen[i, j] = row[j];
		screenForBlind[i, j] = row[j] == 'B' ? 'B' : 'R';
	}
}

int[,] pixelChecked = new int[n, n];

void Checking(int index1, int index2)
{
	pixelChecked[index1, index2] = 1;
	
	if (index1 - 1 >= 0 && screen[index1 - 1, index2] == screen[index1, index2] && pixelChecked[index1 - 1, index2] == 0)
		Checking(index1 - 1, index2);
	
	if (index1 + 1 < n && screen[index1 + 1, index2] == screen[index1, index2] && pixelChecked[index1 + 1, index2] == 0)
		Checking(index1 + 1, index2);
	
	if (index2 - 1 >= 0 && screen[index1, index2 - 1] == screen[index1, index2] && pixelChecked[index1, index2 - 1] == 0)
		Checking(index1, index2 - 1);
	
	if (index2 + 1 < n && screen[index1, index2 + 1] == screen[index1, index2] && pixelChecked[index1, index2 + 1] == 0)
		Checking(index1, index2 + 1);
}

int count = 0;

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (pixelChecked[i, j] == 0)
		{
			Checking(i, j);
			count++;
		}
	}
}

Console.Write($"{count} ");

pixelChecked = new int[n, n];

void CheckingByBlind(int index1, int index2)
{
	pixelChecked[index1, index2] = 1;
	
	if (index1 - 1 >= 0 && screenForBlind[index1 - 1, index2] == screenForBlind[index1, index2] && pixelChecked[index1 - 1, index2] == 0)
		CheckingByBlind(index1 - 1, index2);
	
	if (index1 + 1 < n && screenForBlind[index1 + 1, index2] == screenForBlind[index1, index2] && pixelChecked[index1 + 1, index2] == 0)
		CheckingByBlind(index1 + 1, index2);
	
	if (index2 - 1 >= 0 && screenForBlind[index1, index2 - 1] == screenForBlind[index1, index2] && pixelChecked[index1, index2 - 1] == 0)
		CheckingByBlind(index1, index2 - 1);
	
	if (index2 + 1 < n && screenForBlind[index1, index2 + 1] == screenForBlind[index1, index2] && pixelChecked[index1, index2 + 1] == 0)
		CheckingByBlind(index1, index2 + 1);
}

count = 0;

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (pixelChecked[i, j] == 0)
		{
			CheckingByBlind(i, j);
			count++;
		}
	}
}

Console.WriteLine(count);
