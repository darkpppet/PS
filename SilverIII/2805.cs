using System;
using System.Linq;

string input = Console.ReadLine();

int count = int.Parse(input.Split(" ")[0]);
int neededLength = int.Parse(input.Split(" ")[1]);

int[] treeLengths = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

int left = 0;
int right = treeLengths.Max();
int max = 0;

while (left <= right)
{
    int middle = (left + right) / 2;

    if (treeLengths.Select(x => x > middle ? x - middle : 0).Sum(x => (long)x) >= neededLength)
    {
        max = max > middle ? max : middle;
        left = middle + 1;
    }
    else
    {
        right = middle - 1;
    }
}

Console.WriteLine(max);
