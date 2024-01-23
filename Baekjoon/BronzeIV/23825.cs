using System;

string[] inputs = Console.ReadLine().Split(' ');

(int S, int A) = (int.Parse(inputs[0]), int.Parse(inputs[1]));

Console.WriteLine(Math.Min(S, A) / 2);
