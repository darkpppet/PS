using System;

decimal piD = decimal.Parse("3.14159265358979323846264338327950288419716939937510");
decimal piD2 = piD / 2;
decimal piD4 = piD / 4;

decimal[] sinDenominators = new decimal[30];
decimal[] cosDenominators = new decimal[30];

for (int i = 1; i <= 30; i++)
{
	sinDenominators[i - 1] = 2 * i * (2 * i + 1);
	cosDenominators[i - 1] = (2 * i - 1) * 2 * i;
}

decimal Sin(decimal x)
{
	if (x == 0)
		return decimal.Zero;
	
	if (x < 0)
		return -Sin(-x);
	
	if (x > piD)
		return (int)decimal.Floor(x / piD) % 2 == 0 ? Sin(x % piD) : -Sin(x % piD);
	
	if (x > piD4)
		return Cos(piD2 - x);

	decimal x2 = x * x;
	
	decimal result = 1;
	
	for (int i = 29; i >= 0; i--)
	{
		result = x2 / sinDenominators[i] * result;
		result += i % 2 == 0 ? 1 : -1;
	}

	return x * result;
}

decimal Cos(decimal x)
{
	if (x == 0)
		return decimal.One;
	
	if (x < 0)
		return Cos(-x);
	
	if (x > piD)
		return (int)decimal.Floor(x / piD) % 2 == 0 ? Cos(x % piD) : -Cos(x % piD);
	
	if (x > piD4)
		return Sin(piD2 - x);

	decimal x2 = x * x;
	
	decimal result = 1;
	
	for (int i = 29; i >= 0; i--)
	{
		result = x2 / cosDenominators[i] * result;
		result += i % 2 == 0 ? 1 : -1;
	}

	return result;
}

string[] input = Console.ReadLine().Split(' ');

decimal a = decimal.Parse(input[0]);
decimal b = decimal.Parse(input[1]);
decimal c = decimal.Parse(input[2]);

decimal result = c / a;
decimal beforeResult;

do
{
	beforeResult = result;
	
	decimal sinx = Sin(result);
	decimal cosx = Cos(result);
	
	result = (c + b * result * cosx - b * sinx) / (a + b * cosx);
} while (Decimal.Round(result, 12) != Decimal.Round(beforeResult, 12));

Console.WriteLine(Decimal.Round(result, 6, MidpointRounding.AwayFromZero));
