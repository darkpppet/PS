using System;
using System.Collections.Generic;
using System.Linq;

List<int> scienceScores = new();
List<int> socialScores = new();

for (int i = 0; i < 4; i++)
	scienceScores.Add(int.Parse(Console.ReadLine()));

for (int i = 0; i < 2; i++)
	socialScores.Add(int.Parse(Console.ReadLine()));

Console.WriteLine(scienceScores.Sum() - scienceScores.Min() + socialScores.Max());
