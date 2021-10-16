using System;

char[] input = Console.ReadLine().ToCharArray();

Array.Sort(input, (a, b) => a > b ? -1 : 1);

Console.WriteLine(new String(input));
