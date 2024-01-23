using System;
using System.Collections.Generic;
using System.Linq;

int n = int.Parse(Console.ReadLine());

List<int> list = Enumerable.Range(1, n).ToList();

while (list.Count > 1)
{
    if (list.Count % 2 == 0)
    {
        list = list.Where((_, index) => index % 2 != 0).ToList();
    }
    else
    {
        int bottom = list[^1];
        list = list.Where((_, index) => index % 2 != 0).ToList();
        list.Insert(0, bottom);
    }
}

Console.WriteLine(list[0]);
