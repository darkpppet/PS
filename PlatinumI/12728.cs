using System;

(int A, int B, int C, int D) MulMatrix((int A, int B, int C, int D) matrix1, (int A, int B, int C, int D) matrix2) =>
	((matrix1.A * matrix2.A + matrix1.B * matrix2.C) % 1000,
	 (matrix1.A * matrix2.B + matrix1.B * matrix2.D) % 1000,
	 (matrix1.C * matrix2.A + matrix1.D * matrix2.C) % 1000,
	 (matrix1.C * matrix2.B + matrix1.D * matrix2.D) % 1000);

(int A, int B, int C, int D) PowMatrix((int A, int B, int C, int D) matrix, int exponent)
{
	if (exponent == 0)
		return (1, 0, 0, 1);
	
	if (exponent == 1)
		return matrix;
	
	var sqrt = PowMatrix(matrix, exponent / 2);
	
	return (exponent % 2 == 0 ? MulMatrix(sqrt, sqrt) : MulMatrix(MulMatrix(sqrt, sqrt), matrix));
}

int t = int.Parse(Console.ReadLine());

for (int count = 0; count < t; count++)
{
	int n = int.Parse(Console.ReadLine());
	
	var matrix = PowMatrix((6, -4, 1, 0), n - 1);
	
	int result = (6 * matrix.A + 2 * matrix.B) % 1000;
	
	result += result < 0 ? 999 : -1;
	
	Console.WriteLine($"Case #{count + 1}: {result:D3}");
}
