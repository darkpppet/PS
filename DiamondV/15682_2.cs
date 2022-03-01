using System;
using System.Text;
using System.Collections.Generic;

int accuracy2 = 28;

decimal SqrtDecimal(decimal x)
{
	if (x == 0)
		return 0;
	
	decimal before = (decimal)Math.Sqrt((double)x);
	decimal now = (before + x / before) / 2;
	
	while (Math.Abs(now - before) > 0m)
	{
		before = now;
		now = (before + x / before) / 2;
	}
	
	return now;
}

int n = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int t = 0; t < n; t++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	decimal a = decimal.Parse(input[0]);
	decimal b = decimal.Parse(input[1]);
	decimal c = decimal.Parse(input[2]);
	decimal d = decimal.Parse(input[3]);
	
	if (a < 0)
	{
		a = -a;
		b = -b;
		c = -c;
		d = -d;
	}
	
	decimal Calc(decimal x) => x * (x * (x * a + b) + c) + d;
	decimal CalcD(decimal x) => x * (x * 3 * a + 2 * b) + c;
	
	decimal inflectionPoint = -b / (3 * a);

	if (CalcD(inflectionPoint) >= 0)
	{
		int left = -1_000_000;
		int right = 1_000_000;
		int middle = 0;
		
		while (left <= right)
		{
			middle = (left + right) / 2;
			
			if (Math.Round(Calc(middle), accuracy2) == 0)
			{
				outputBuilder.AppendLine(middle.ToString());
				break;
			}
			else if (Calc(middle) > 0)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
	}
	else
	{
		decimal l = SqrtDecimal(b * b - 3 * a * c);
		
		decimal localExtremumPointLeft = (-b - l) / (3 * a);
		decimal localExtremumPointRight = (-b + l) / (3 * a);
		
		decimal localExtremumValueLeft = Calc(localExtremumPointLeft);
		decimal localExtremumValueRight = Calc(localExtremumPointRight);
		
		decimal intervalLeft = (-b - 2 * l) / (3 * a);
		decimal intervalRight = (-b + 2 * l) / (3 * a);
		
		switch (localExtremumValueLeft * localExtremumValueRight)
		{
			case decimal f when Math.Round(f, accuracy2) == 0:
				if (Math.Round(localExtremumValueLeft, accuracy2) == 0)
				{
					if (localExtremumPointLeft == Math.Round(localExtremumPointLeft))
						outputBuilder.AppendLine($"{Math.Round(localExtremumPointLeft)} {intervalRight}");
					else
						outputBuilder.AppendLine($"{localExtremumPointLeft} {Math.Round(intervalRight)}");
				}
				else
				{
					if (localExtremumPointRight == Math.Round(localExtremumPointRight))
						outputBuilder.AppendLine($"{intervalLeft} {Math.Round(localExtremumPointRight)}");
					else
						outputBuilder.AppendLine($"{Math.Round(intervalLeft)} {localExtremumPointRight}");
				}
				
				break;
				
			case decimal f when f > 0:
				if (localExtremumValueLeft + localExtremumValueRight < 0)
				{
					int left = (int)Math.Floor(intervalRight);
					int right = 1_000_000;
					int middle = 0;
					
					while (left <= right)
					{
						middle = (left + right) / 2;
						
						if (Math.Round(Calc(middle), accuracy2) == 0)
						{
							outputBuilder.AppendLine(middle.ToString());
							break;
						}
						else if (Calc(middle) > 0)
						{
							right = middle - 1;
						}
						else
						{
							left = middle + 1;
						}
					}
				}
				else
				{
					int left = -1_000_000;
					int right = (int)Math.Ceiling(intervalLeft);
					int middle = 0;
					
					while (left <= right)
					{
						middle = (left + right) / 2;
						
						if (Math.Round(Calc(middle), accuracy2) == 0)
						{
							outputBuilder.AppendLine(middle.ToString());
							break;
						}
						else if (Calc(middle) > 0)
						{
							right = middle - 1;
						}
						else
						{
							left = middle + 1;
						}
					}
				}
				
				break;
			
			case decimal f when f < 0:
				{
					bool isFoundIntroot = false;
					
					List<decimal> xes = new();
					
					int left;
					int right;
					int middle;
					
					left = (int)Math.Max(-1_000_000, (int)Math.Ceiling(intervalLeft));
					right = (int)Math.Floor(localExtremumPointLeft);
					
					while ((left <= right) && !isFoundIntroot)
					{
						middle = (left + right) / 2;
						
						if (Math.Round(Calc(middle), accuracy2) == 0)
						{
							xes.Add(middle);
							isFoundIntroot = true;
							break;
						}
						else if (Calc(middle) > 0)
						{
							right = middle - 1;
						}
						else
						{
							left = middle + 1;
						}
					}
					
					left = (int)Math.Ceiling(localExtremumPointLeft);
					right = (int)Math.Floor(localExtremumPointRight);
					
					while ((left <= right) && !isFoundIntroot)
					{
						middle = (left + right) / 2;
						
						if (Math.Round(Calc(middle), accuracy2) == 0)
						{
							xes.Add(middle);
							isFoundIntroot = true;
							break;
						}
						else if (Calc(middle) < 0)
						{
							right = middle - 1;
						}
						else
						{
							left = middle + 1;
						}
					}
					
					left = (int)Math.Ceiling(localExtremumPointRight);
					right = (int)Math.Min((int)Math.Floor(intervalRight), 1_000_000);
					
					while ((left <= right) && !isFoundIntroot)
					{
						middle = (left + right) / 2;
						
						if (Math.Round(Calc(middle), accuracy2) == 0)
						{
							xes.Add(middle);
							isFoundIntroot = true;
							break;
						}
						else if (Calc(middle) > 0)
						{
							right = middle - 1;
						}
						else
						{
							left = middle + 1;
						}
					}
					
					decimal p = a * xes[0] + b;
					decimal q = c + p * xes[0];
					
					decimal sqrt = SqrtDecimal(p * p - 4 * a * q);
					
					xes.Add((-p - sqrt) / (2 * a));
					xes.Add((-p + sqrt) / (2 * a));
					
					xes.Sort();
					
					outputBuilder.AppendLine($"{xes[0]} {xes[1]} {xes[2]}");
				}
				
				break;
		}
	}
}

Console.Write(outputBuilder.ToString());
