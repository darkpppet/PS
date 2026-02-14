using System;

string str1 = Console.ReadLine();
string str2 = Console.ReadLine();

int[,] lcs = new int[str1.Length + 1, str2.Length + 1];
int[,] checkedIndex = new int[str1.Length + 1, str2.Length + 1];

for (int i = 0; i <= str1.Length; i++)
{
	checkedIndex[i, 0] = 1;
	lcs[i, 0] = 0;
}

for (int j = 0; j <= str2.Length; j++)
{
	checkedIndex[0, j] = 1;
	lcs[0, j] = 0;
}

void CalcLcs(int i, int j)
{
	if (checkedIndex[i, j] == 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			CalcLcs(i - 1, j - 1);
			
			lcs[i, j] = lcs[i - 1, j - 1] + 1;
		}
		else
		{
			CalcLcs(i - 1, j);
			CalcLcs(i , j - 1);
			
			lcs[i, j] = Math.Max(lcs[i - 1, j], lcs[i, j - 1]);
		}
		
		checkedIndex[i, j] = 1;
	}
}

CalcLcs(str1.Length, str2.Length);

Console.WriteLine(lcs[str1.Length, str2.Length]);
