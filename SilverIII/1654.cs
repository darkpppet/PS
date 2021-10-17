using System;
using System.Linq;

string input = Console.ReadLine();

int k = int.Parse(input.Split(' ')[0]);
int n = int.Parse(input.Split(' ')[1]);

int[] cableLengths = new int[k];

for (int i = 0; i < k; i++)
    cableLengths[i] = int.Parse(Console.ReadLine());

long left = 1;
long right = cableLengths.Max();

long max = 1;

while (left <= right)
{
    int count = 0;
    long middle = (left + right) / 2;

    foreach (int cableLength in cableLengths)
        count += cableLength / (int)middle;

    if (count >= n)
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
