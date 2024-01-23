using System;
using System.Linq;

int n = int.Parse(Console.ReadLine());

int constructor = 0;

for (int i = 1; i <= n; i++)
{
    int num = i + i.ToString().Select(x => x - '0').Sum();

    if (num == n)
    {
        constructor = i;
        break;
    }
}

Console.WriteLine(constructor);
