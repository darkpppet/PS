using System;
using System.Text;

StringBuilder outputBuilder = new();

long n = long.Parse(Console.ReadLine());

for (long i = 2; n > 1; i++)
{
	if (n % i == 0)
	{
		n /= i;
		outputBuilder.AppendLine(i.ToString());
		i--;
	}
}

Console.Write(outputBuilder.ToString());
