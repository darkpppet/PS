using System;
using System.Linq;

Console.ReadLine();
int[] numbers = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

Console.WriteLine(numbers.Max() + " " + numbers.Min());
