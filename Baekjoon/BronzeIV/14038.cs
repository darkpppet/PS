using System;
using System.Linq;

string[] array = new string[6];

for (int i = 0; i < 6; i++)
	array[i] = Console.ReadLine();

Console.WriteLine(array.Count(x => x == "W") switch
				  {
					  5 or 6 => 1,
					  3 or 4 => 2,
					  1 or 2 => 3,
					  _ => -1
				  });
