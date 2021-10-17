using System;
using System.Linq;

int[] numbers = new int[10];

for (int i = 0; i < 10; i++)
    numbers[i] = int.Parse(Console.ReadLine());

bool[] isExist = Enumerable.Repeat(false, 42).ToArray();

foreach (int i in numbers)
    isExist[i % 42] = true;

Console.WriteLine(isExist.Count(x => x == true));
