using System;
using System.Text;
using System.Collections.Generic;

int m = int.Parse(Console.ReadLine().Split(" ")[1]);

int[] array = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

List<int> sumList = new() { 0 };
int sum = 0;

foreach (int i in array)
{
	sum += i;
	sumList.Add(sum);
}

StringBuilder outputBuilder = new();

for (int k = 0; k < m; k++)
{
	string[] input = Console.ReadLine().Split(" ");
	
	int i = int.Parse(input[0]);
	int j = int.Parse(input[1]);
	
	outputBuilder.AppendLine((sumList[j] - sumList[i - 1]).ToString());
}

Console.Write(outputBuilder.ToString());
