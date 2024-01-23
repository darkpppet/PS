using System;

long[,] MulMatrix(long[,] matrix1, long[,] matrix2)
{
	int l = (int)Math.Sqrt(matrix1.Length);
	
	long[,] resultMatrix = new long[l, l];
	
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < l;k++)
				resultMatrix[i, j] += matrix1[i, k] * matrix2[k, j];
		}
	}
	
	return resultMatrix;
}

long[,] PowMatrix(long[,] matrix, long exp)
{
	if (exp == 1)
		return matrix;
	
	long[,] sqrtMatrix = PowMatrix(matrix, exp / 2);
	
	if (exp % 2 == 0)
		return MulMatrix(sqrtMatrix, sqrtMatrix);
	else
		return MulMatrix(MulMatrix(sqrtMatrix, sqrtMatrix), matrix);
}

string[] input = Console.ReadLine().Split(' ');

long k = long.Parse(input[0]);
long n = long.Parse(input[1]);




