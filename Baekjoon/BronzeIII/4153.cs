using System;
using System.Linq;

while (true)
{
    int[] lenghts = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

    if (lenghts.SequenceEqual(new int[] { 0, 0, 0 }))
        break;

    Array.Sort(lenghts);

    if (lenghts[2] * lenghts[2] == lenghts[0] * lenghts[0] + lenghts[1] * lenghts[1])
        Console.WriteLine("right");
    else
        Console.WriteLine("wrong");
}
