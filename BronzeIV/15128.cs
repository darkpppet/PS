using System;

long[] input = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);

long numerator = input[0] * input[2];
long denominator = 2 * input[1] * input[3];

Console.WriteLine(numerator % denominator == 0 ? 1 : 0);
