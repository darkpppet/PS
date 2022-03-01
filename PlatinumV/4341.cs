using System;
using System.Text;

int t = int.Parse(Console.ReadLine());

StringBuilder outputBuilder = new();

for (int tCase = 0; tCase < t; tCase++)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int p = 0;
	int q = 0;
	
	string[] input = Console.ReadLine().Split(' ');
	
	bool isPlus = true;
	bool isLeft = true;
	
	foreach (string term in input)
	{
		switch (term[^1])
		{
			case 'x':
				string coefString = term.Substring(0, term.Length - 1);
				int coef = coefString switch
				{
						"" => 1,
						"-" => -1,
						_ => int.Parse(coefString)
				};
				
				if (!(isPlus ^ isLeft))
					a += coef;
				else
					a -= coef;
				
				break;
				
			case 'y':
				string coefString = term.Substring(0, term.Length - 1);
				int coef = coefString switch
				{
						"" => 1,
						"-" => -1,
						_ => int.Parse(coefString)
				};
				
				if (!(isPlus ^ isLeft))
					b += coef;
				else
					b -= coef;
				
				break;
				
			case '=':
				isLeft = false;
				break;
				
			case '+':
				isPlus = true;
				break;
				
			case '-':
				isPlus = false;
				break;
				
			default:
				if (!(isPlus ^ isLeft))
					p -= int.Parse(term);
				else
					p += int.Parse(term);
				break;
		}
	}
	
	input = Console.ReadLine().Split(' ');
	
	isPlus = true;
	isLeft = true;
	
	foreach (string term in input)
	{
		switch (term[^1])
		{
			case 'x':
				string coefString = term.Substring(0, term.Length - 1);
				int coef = coefString switch
				{
						"" => 1,
						"-" => -1,
						_ => int.Parse(coefString)
				};
				
				if (!(isPlus ^ isLeft))
					c += coef;
				else
					c -= coef;
				
				break;
				
			case 'y':
				string coefString = term.Substring(0, term.Length - 1);
				int coef = coefString switch
				{
						"" => 1,
						"-" => -1,
						_ => int.Parse(coefString)
				};
				
				if (!(isPlus ^ isLeft))
					d += coef;
				else
					d -= coef;
				
				break;
				
			case '=':
				isLeft = false;
				break;
				
			case '+':
				isPlus = true;
				break;
				
			case '-':
				isPlus = false;
				break;
				
			default:
				if (!(isPlus ^ isLeft))
					q -= int.Parse(term);
				else
					q += int.Parse(term);
				break;
		}
	}
	
	if (a * d == b * c)
	{
		outputBuilder.AppendLine("Dont");
	}
	else
	{
		outputBuilder.AppendLine(((d * p - b * q) / (a * d - b * c)).ToString());
		outputBuilder.AppendLine(((a * q - c * p) / (a * d - b * c)).ToString());
		outputBuilder.AppendLine();
	}
	
	Console.ReadLine();
}

Console.Write(outputBuilder.ToString());
