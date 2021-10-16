using System;

int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
int[] r = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

int sum = 0;

for (int i = 0; i < 3; i++)
	sum += r[i] - a[i] > 0 ? r[i] - a[i] : 0;

Console.WriteLine(sum);
