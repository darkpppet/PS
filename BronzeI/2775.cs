using System;
using System.Collections.Generic;
using System.Linq;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    int k = int.Parse(Console.ReadLine());
    int n = int.Parse(Console.ReadLine());

    List<int[]> apart = new();

    apart.Add(Enumerable.Range(1, n).ToArray());

    for (int j = 1; j <= k; j++)
    {
        int[] floor = new int[n];

        floor[0] = 1;

        for (int l = 1; l < n; l++)
            floor[l] = floor[l - 1] + apart[j - 1][l];

        apart.Add(floor);
    }

    Console.WriteLine(apart[k][n - 1]);
}
