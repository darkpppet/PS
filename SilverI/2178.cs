using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);

int[,] map = new int[n, m];

for (int i = 0; i < n; i++)
{
	int[] inputLine = Array.ConvertAll(Console.ReadLine().ToCharArray(), x => x - '0');
	
	for (int j = 0; j < m; j++)
		map[i, j] = inputLine[j];
}

HashSet<(int Xpos, int Ypos)> before = new() { (0, 0) };

int count = 1;

while (!before.Contains((m - 1, n - 1)))
{
	HashSet<(int Xpos, int Ypos)> tempSet = new();
	
	foreach ((int Xpos, int Ypos) in before)
	{
		if (Xpos - 1 >= 0 && map[Ypos, Xpos - 1] == 1)
			tempSet.Add((Xpos - 1, Ypos));
		
		if (Xpos + 1 < m && map[Ypos, Xpos + 1] == 1)
			tempSet.Add((Xpos + 1, Ypos));
		
		if (Ypos - 1 >= 0 && map[Ypos - 1, Xpos] == 1)
			tempSet.Add((Xpos, Ypos - 1));
		
		if (Ypos + 1 < n && map[Ypos + 1, Xpos] == 1)
			tempSet.Add((Xpos, Ypos + 1));
	}
	
	before = new(tempSet);
	
	count++;
}

Console.WriteLine(count);
