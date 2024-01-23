using System;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] graphMatrix = new int[n, n];

for (int i = 0; i < m; i++)
{
	input = Console.ReadLine().Split(" ");
	
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
	
	graphMatrix[a - 1, b - 1] = 1;
	graphMatrix[b - 1, a - 1] = 1;
}

int[] checkedPoint = new int[n];

void Check(int num)
{
	if (checkedPoint[num] == 1)
		return;
	
	checkedPoint[num] = 1;
	
	for (int i = 0 ; i < n; i++)
	{
		if (graphMatrix[num, i] == 1)
			Check(i);
	}
}

int connectedComponent = 0;

for (int i = 0; i < n; i++)
{
	if (checkedPoint[i] == 0)
	{
		Check(i);
		connectedComponent++;
	}
}

Console.WriteLine(connectedComponent);
