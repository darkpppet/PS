using System;
using System.Text;

StringBuilder outputBuilder = new();

int countT = int.Parse(Console.ReadLine());

for (int count = 0; count < countT; count++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int k = int.Parse(input[0]);
	int c = int.Parse(input[1]);
	
	int GCD(int a, int b)
	{
		if (a < b)
			return GCD(b, a);
		
		if (b == 0)
			return a;
		
		return GCD(b, a % b);
	}
	
	int d = GCD(k, c);
	
	if (d != 1)
	{
		outputBuilder.AppendLine("IMPOSSIBLE");
	}
	else
	{
		int si2 = 1;
		int si1 = 0;
		int si;
		
		int ti2 = 0;
		int ti1 = 1;
		int ti;
		
		int ri2 = k;
		

		
		while (ri != 0)
		{
			
		}
		
		
		if (isSwitch)
		{
			
		}
		else
		{
			
		}
	}
}

Console.Write(outputBuilder.ToString());
