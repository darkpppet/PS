using System;
using System.Collections.Generic;
using System.Linq;

int count = int.Parse(Console.ReadLine());

List<int> list = new();
Dictionary<int, int> mode = new();

for (int i = 0; i < count; i++)
    list.Add(int.Parse(Console.ReadLine()));

foreach (int i in list)
{
    if (mode.ContainsKey(i))
        mode[i]++;
    else
        mode[i] = 1;
}

List<int> modes = new();

foreach (int key in mode.Keys)
{
    if (mode[key] == mode.Values.Max())
        modes.Add(key);
}

list.Sort();
modes.Sort();

Console.WriteLine(Math.Round(list.Average()));
Console.WriteLine(list[list.Count / 2]);
Console.WriteLine(modes.Count == 1 ? modes[0] : modes[1]);
Console.WriteLine(list.Max() - list.Min());
