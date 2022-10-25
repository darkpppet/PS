using System;
using System.Linq;

int[] numbers = new int[9];

for (int i = 0; i < 9; i++)
    numbers[i] = int.Parse(Console.ReadLine());

Console.WriteLine(numbers.Max());
Console.WriteLine(Array.IndexOf(numbers, numbers.Max()) + 1);
