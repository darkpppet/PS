using System;

int n = int.Parse(Console.ReadLine());

int count = 0;

void Queen(int row, int[,] map)
{
	if (row == n)
	{
		count++;
		return;
	}
	
	for (int column = 0; column < n; column++)
	{
		if (map[0, column] == 0)
		{
			int newMapHeight = n - 1 - row;
			int[,] newMap = new int[newMapHeight, n];
			
			Array.Copy(map, n, newMap, 0, newMapHeight * n);
			
			for (int i = 0; i < newMapHeight; i++)
				newMap[i, column] = 1;
			
			int tempRow = 0;
			int tempLeftColumn = column - 1;
			int tempRightColumn = column + 1;
			
			for (; tempRow < newMapHeight && (tempLeftColumn >= 0 || tempRightColumn < n) ; tempRow++, tempLeftColumn--, tempRightColumn++)
			{
				if (tempLeftColumn >= 0)
					newMap[tempRow, tempLeftColumn] = 1;
				
				if (tempRightColumn < n)
					newMap[tempRow, tempRightColumn] = 1;
			}
			
			Queen(row + 1, newMap);
		}
	}
}

Queen(0, new int[n, n]);

Console.WriteLine(count);
