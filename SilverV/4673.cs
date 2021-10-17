using System;
using System.Linq;

int[] dn = new int[10000];

for (int i = 1; i <= 10000; i++)
{
    dn[i - 1] = i;
    foreach (char c in i.ToString())
        dn[i - 1] += int.Parse(c.ToString());
}

for (int i = 1; i <= 10000; i++)
{
    if (!dn.Any(x => x == i))
        Console.WriteLine(i);
}
