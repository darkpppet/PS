using System;
using System.Collections.Generic;
using System.Linq;

int n = int.Parse(Console.ReadLine());

(int I, int J) babyLocation = (0, 0);
int babyLevel = 2;
int babyExp = 2;

int[,] space = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
	{
		space[i, j] = row[j];
		
		if (row[j] == 9)
		{
			babyLocation = (i, j);
			space[i, j] = 0;
		}
	}
}

int time = 0;

int temptime = 0;
int[,] spaceChecked = new int[n, n];

bool CanMove(int index1, int index2) => index1 >= 0 && index1 < n && index2 >= 0 && index2 < n && spaceChecked[index1, index2] == 0 && space[index1, index2] <= babyLevel;

List<(int I, int J)> before = new() { babyLocation };
spaceChecked[babyLocation.I, babyLocation.J] = 1;

while (before.Count > 0)
{
	if (before.Any(x => space[x.I, x.J] != 0 && space[x.I, x.J] < babyLevel))
	{
		babyLocation = before.Where(x => space[x.I, x.J] != 0 && space[x.I, x.J] < babyLevel).Aggregate((a, b) => (a.I < b.I || (a.I == b.I && a.J < b.J)) ? a : b);
		babyExp = --babyExp == 0 ? ++babyLevel : babyExp;
		space[babyLocation.I, babyLocation.J] = 0;
		time += temptime;
		temptime = 0;
		spaceChecked = new int[n, n];
		before = new() { babyLocation };
		spaceChecked[babyLocation.I, babyLocation.J] = 1;
		continue;
	}
	
	List<(int I, int J)> tempBefore = new();
	
	foreach ((int I, int J) in before)
	{
		if (CanMove(I - 1, J))
		{
			tempBefore.Add((I - 1, J));
			spaceChecked[I - 1, J] = 1;
		}
		
		if (CanMove(I, J - 1))
		{
			tempBefore.Add((I, J - 1));
			spaceChecked[I, J - 1] = 1;
		}
		
		if (CanMove(I, J + 1))
		{
			tempBefore.Add((I, J + 1));
			spaceChecked[I, J + 1] = 1;
		}
		
		if (CanMove(I + 1, J))
		{
			tempBefore.Add((I + 1, J));
			spaceChecked[I + 1, J] = 1;
		}
	}
	
	temptime++;
	before = new(tempBefore);
}

Console.WriteLine(time);
