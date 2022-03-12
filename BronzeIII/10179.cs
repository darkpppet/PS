using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
	Console.WriteLine($"${double.Parse(Console.ReadLine()) * 0.8:.00}");
