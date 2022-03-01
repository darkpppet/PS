using System;

int n = int.Parse(Console.ReadLine());

int count5 = 0;

for (int i = 5; i <= n; i *= 5)
	count5 += n / i;

Console.WriteLine(count5);
