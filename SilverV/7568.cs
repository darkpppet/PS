using System;
using System.Linq;

int count = int.Parse(Console.ReadLine());
(int Weight, int Height)[] array = new (int, int)[count];

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    array[i].Weight = int.Parse(input.Split(" ")[0]);
    array[i].Height = int.Parse(input.Split(" ")[1]);
}

foreach ((int Weight, int Height) in array)
    Console.Write(array.Count(x => x.Weight > Weight && x.Height > Height) + 1 + " ");
