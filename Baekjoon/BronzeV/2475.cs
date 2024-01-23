using System;

int[] numbers = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

Console.WriteLine((numbers[0] * numbers[0] + numbers[1] * numbers[1] + numbers[2] * numbers[2] + numbers[3] * numbers[3] + numbers[4] * numbers[4]) % 10);
