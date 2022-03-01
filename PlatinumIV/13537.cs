using System;
using System.Text;
using System.Linq;

int n = int.Parse(Console.ReadLine());

int[] array = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

StringBuilder outputBuilder = new();

int m = int.Parse(Console.ReadLine());

for (int t = 0; t < m; t++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int i = int.Parse(input[0]);
	int j = int.Parse(input[1]);
	int k = int.Parse(input[2]);
	
	outputBuilder.AppendLine(array[(i - 1)..j].Count(x => x > k).ToString());
}

Console.Write(outputBuilder.ToString());
