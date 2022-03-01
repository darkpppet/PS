using System;

int[] apple = new int[3];
int[] banana = new int[3];

for (int i = 0; i < 3; i++)
	apple[i] = int.Parse(Console.ReadLine());

for (int i = 0; i < 3; i++)
	banana[i] = int.Parse(Console.ReadLine());

int appleScore = 3 * apple[0] + 2 * apple[1] + apple[2];
int bananaScore = 3 * banana[0] + 2 * banana[1] + banana[2];

if (appleScore == bananaScore)
	Console.WriteLine('T');
else
	Console.WriteLine(appleScore > bananaScore ? 'A' : 'B');
