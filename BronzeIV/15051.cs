using System;
using System.Linq;

int a1 = int.Parse(Console.ReadLine());
int a2 = int.Parse(Console.ReadLine());
int a3 = int.Parse(Console.ReadLine());

int[] times = new int[3];

times[0] = 2 * (a1 + a3);
times[1] = 2 * (a2 + a3 * 2);
times[2] = 2 * (a1 * 2 + a2);

Console.WriteLine(times.Min());
