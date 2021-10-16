using System;
using System.IO;
using System.Text;
using System.Linq;

StreamReader streamReader = new(Console.OpenStandardInput());

int count = int.Parse(streamReader.ReadLine());

int[] countingArr = Enumerable.Repeat<int>(0, 10000).ToArray<int>();

for (int i = 0; i < count; i++)
	countingArr[int.Parse(streamReader.ReadLine())- 1]++;

StringBuilder outputBuilder = new();

StreamWriter streamWriter = new(Console.OpenStandardOutput());
streamWriter.AutoFlush = true;

for (int i = 0; i < 10000; i++)
{
	for (int j = 0; j < countingArr[i]; j++)
	{
		outputBuilder.AppendLine((i + 1).ToString());
		
		if (outputBuilder.Length > 1600)
		{
			streamWriter.Write(outputBuilder.ToString());
			outputBuilder.Clear();
		}
	}
}

streamWriter.Write(outputBuilder.ToString());
