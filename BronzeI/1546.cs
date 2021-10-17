using System;
using System.Linq;

Console.ReadLine();
double[] scores = Array.ConvertAll(Console.ReadLine().Split(" "), x => double.Parse(x));

scores = Array.ConvertAll(scores, x => x / scores.Max() * 100);

Console.WriteLine(scores.Average());
