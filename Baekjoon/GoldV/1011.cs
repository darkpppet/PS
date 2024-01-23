using System;

int t = int.Parse(Console.ReadLine());

for (int i = 0; i < t; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int x = int.Parse(input[0]);
	int y = int.Parse(input[1]);
	
	int length = y - x;
	
	int n = (int)Math.Ceiling(Math.Sqrt(length));
	int gap = n * n - length;
	
	Console.WriteLine(2 * n - (gap >= 0 && gap <= n - 1 ? 1 : 2));
}
