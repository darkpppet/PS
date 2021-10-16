using System;
using System.Text;

StringBuilder outputBuilder = new();

int n = int.Parse(Console.ReadLine());

for (int i = 0; i < n; i++)
	outputBuilder.AppendLine("SciComLove");

Console.Write(outputBuilder.ToString());
