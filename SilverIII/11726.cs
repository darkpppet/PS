using System;
using System.Numerics;

int n = int.Parse(Console.ReadLine());

BigInteger Factorial(int num)
{
	if (num == 0)
		return 1;
	
	BigInteger result = 1;
	
	for (int i = 2; i <= num; i++)
		result *= (BigInteger)i;
	
	return result;
}

BigInteger count = 0;

for (int horizontalCount = 0; horizontalCount * 2 <= n; horizontalCount++)
{
	int verticalCount = n - horizontalCount * 2;
	
	count += Factorial(horizontalCount + verticalCount) / (Factorial(horizontalCount) * Factorial(verticalCount));
}

Console.WriteLine(count % 10007);
