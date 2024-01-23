using System;

Console.ReadLine();
int[] numbers = Array.ConvertAll(Console.ReadLine().ToCharArray(), x => int.Parse(x.ToString()));

int sum = 0;

foreach (int i in numbers)
    sum += i;

Console.WriteLine(sum);
