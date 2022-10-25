using System;

int n = int.Parse(Console.ReadLine());

double[] radii = Array.ConvertAll(Console.ReadLine().Split(' '), double.Parse);

double min = 0;
for (int i = 0; i < n - 1; i++)
	min += Math.Sqrt(radii[i] * radii[i + 1]);

void Calc(double[] permutation, int[] checkedIndex, int count)
{
	if (count == n)
	{
		double result = 0;
		
		for (int i = 0; i < n - 1; i++)
			result += Math.Sqrt(permutation[i] * permutation[i + 1]);
		
		min = Math.Min(min, result);
		
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (checkedIndex[i] == 0)
		{
			double[] newPermutation = permutation.Clone() as double[];
			int[] newCheckedIndex = checkedIndex.Clone() as int[];
			
			newCheckedIndex[i] = 1;
			newPermutation[count] = radii[i];
			
			Calc(newPermutation, newCheckedIndex, count + 1);
		}
	}
}

Calc(new double[n], new int[n], 0);

Console.WriteLine(2 * min);
