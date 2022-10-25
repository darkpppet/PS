using System;
using System.Linq;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    int[] scores = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x)).Skip(1).ToArray();

    Console.WriteLine("{0:N3}%", (double)scores.Count(x => x > scores.Average()) / (double)scores.Length * 100);
}
