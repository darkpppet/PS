using System;

int sum = 0;

for (int i = 0; i < 4; i++)
	sum += int.Parse(Console.ReadLine());

Console.WriteLine(sum / 60);
Console.WriteLine(sum % 60);
