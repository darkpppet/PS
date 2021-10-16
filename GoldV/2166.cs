using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<(long Xpos, long Ypos)> points = new();

for (int i = 0; i < n; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	points.Add((long.Parse(input[0]), long.Parse(input[1])));
}

points.Add(points[0]);

decimal area = 0;

for (int i = 0; i < n; i++)
	area += points[i].Xpos * points[i + 1].Ypos - points[i + 1].Xpos * points[i].Ypos;

area /= 2;

area = Math.Abs(area);

Console.WriteLine($"{area:F1}");
