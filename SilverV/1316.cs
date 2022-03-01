using System;
using System.Linq;

int wordCount = int.Parse(Console.ReadLine());

int count = 0;

for (int i = 0; i < wordCount; i++)
{
	bool[] isAppeared = Enumerable.Repeat(false, 26).ToArray();
	
	char[] wordArray = Console.ReadLine().ToCharArray();
	
	char before = wordArray[0];
	
	bool isGroupWord = true;
	
	for (int j = 1; j < wordArray.Length; j++)
	{
		if (wordArray[j] != before)
		{
			if (isAppeared[wordArray[j] - 97])
			{
				isGroupWord = false;
				break;
			}
			
			isAppeared[before - 97] = true;
		}
		
		before = wordArray[j];
	}
	
	if (isGroupWord)
		count++;	
}

Console.WriteLine(count);
