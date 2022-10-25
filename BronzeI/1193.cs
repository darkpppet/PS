using System;

int x = int.Parse(Console.ReadLine());

int n = 0;

for (int i = 0; ; i++)
{
	if (i * (i + 1) < 2 * x && 2 * x <= (i + 1) * (i + 2))
	{
		n = i;
		break;
	}
}

if (n % 2 == 0)
	Console.WriteLine((n + 2 - x + n * (n + 1) / 2) + "/" + (x - n * (n + 1) / 2));
else
	Console.WriteLine((x - n * (n + 1) / 2) + "/" + (n + 2 - x + n * (n + 1) / 2));
