using System;
using System.Numerics;

string[] input = Console.ReadLine().Split(' ');

BigInteger a = BigInteger.Parse(input[0]);
int b = int.Parse(input[1]);
BigInteger c = BigInteger.Parse(input[2]);

BigInteger Pow(BigInteger numA, int numB)
{
	if (numB == 1)
		return numA % c;
	
	BigInteger sqrt = Pow(numA, numB / 2);
	
	return (numB % 2 == 0 ? sqrt * sqrt : sqrt * sqrt * numA) % c;
}

Console.WriteLine(Pow(a % c, b));
