using System;

char[] input = Console.ReadLine().ToCharArray();
char[] mine = Console.ReadLine().ToCharArray();

char[] array = new char[input.Length];
int lastindex = 0;

for (int i = 0; i < input.Length; i++)
{
	array[lastindex] = input[i];
	lastindex++;
	
	bool isFound = lastindex >= mine.Length;
	
	for (int j = 1; lastindex >= mine.Length && j <= mine.Length; j++)
	{
		if (mine[^j] != array[lastindex - j])
		{
			isFound = false;
			break;
		}
	}
	
	if (isFound)
		lastindex -= mine.Length;
}

Console.WriteLine(lastindex > 0 ? new string(array[0..lastindex]) : "FRULA");
