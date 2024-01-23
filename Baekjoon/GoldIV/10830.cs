using System;
using System.Text;

string[] input = Console.ReadLine().Split(' ');

int n = int.Parse(input[0]);
long b = long.Parse(input[1]);

int[,] matrix = new int[n, n];

for (int i = 0; i < n; i++)
{
	int[] row = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
	
	for (int j = 0; j < n; j++)
		matrix[i, j] = row[j] % 1000;
}

int[,] MatrixMultiply(int[,] matrix1, int[,] matrix2)
{
	int[,] product = new int[n, n];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int result = 0;
			
			for (int k = 0; k < n; k++)
			{
				result += matrix1[i, k] * matrix2[k, j];
				result %= 1000;
			}
			
			product[i, j] = result;
		}
	}
	
	return product; 
}

int[,] MatrixPow(int[,] baseMatrix, long exponent)
{
	if (exponent == 1)
		return baseMatrix.Clone() as int[,];
	
	int[,] sqrtMatrix = MatrixPow(baseMatrix, exponent / 2);
		
	if (exponent % 2 == 0)
		return MatrixMultiply(sqrtMatrix, sqrtMatrix);
	else
		return MatrixMultiply(MatrixMultiply(sqrtMatrix, sqrtMatrix), baseMatrix);
}

int[,] result = MatrixPow(matrix, b);

StringBuilder outputBuilder = new();

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		outputBuilder.Append($"{result[i, j]} ");
	
	outputBuilder.AppendLine();
}

Console.Write(outputBuilder.ToString());
