using System;
using System.Linq;

string input = Console.ReadLine();

int n = int.Parse(input.Split(" ")[0]);
int b = int.Parse(input.Split(" ")[2]);

int[] map = Enumerable.Repeat<int>(0, 257).ToArray<int>();

for (int i = 0; i < n; i++)
{
	string[] heights = Console.ReadLine().Split(" ");
	
	foreach (string height in heights)
		map[int.Parse(height)]++;
}

int bottom = 0;

for (int i = 0; i <= 256; i++)
{
	if (map[i] > 0)
	{
		bottom = i;
		break;
	}
}

int top = 0;

for (int i = 256; i >= 0; i--)
{
	if (map[i] > 0)
	{
		top = i;
		break;
	}
}

int time = 0;

while (bottom < top)
{
	if (b >= map[bottom] && map[bottom] <= map[top] * 2)
	{
		time += map[bottom];
		b -= map[bottom];
		map[bottom + 1] += map[bottom];
		map[bottom] = 0;
		bottom++;
	}
	else
	{
		time += map[top] * 2;
		b += map[top];
		map[top - 1] += map[top];
		map[top] = 0;
		top--;
	}
}

Console.WriteLine(time + " " + top);
