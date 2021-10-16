using System;
using System.Linq;

int computerCount = int.Parse(Console.ReadLine());
int lineCount = int.Parse(Console.ReadLine());

int[,] graphMatrix = new int[computerCount, computerCount];

for (int i = 0; i < lineCount; i++)
{
	string[] input = Console.ReadLine().Split(" ");
	
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
	
	graphMatrix[a - 1, b - 1] = 1;
	graphMatrix[b - 1, a - 1] = 1;
}

int[] virusComputers = new int[computerCount];
int[] infectComputers = new int[computerCount];

virusComputers[0] = 1;

while (!Enumerable.SequenceEqual(virusComputers, infectComputers))
{
	for (int i = 0; i < computerCount; i++)
	{
		if (virusComputers[i] == 1 && infectComputers[i] == 0)
		{
			for (int j = 0; j < computerCount; j++)
			{
				if (graphMatrix[i, j] == 1)
					virusComputers[j] = 1;
			}
			
			infectComputers[i] = 1;
		}
	}
}

Console.WriteLine(virusComputers.Count(x => x == 1) - 1);
