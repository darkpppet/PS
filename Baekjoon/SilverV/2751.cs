using System;
using System.Text;
using System.Collections.Generic;

List<int> list = new();
StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
    list.Add(int.Parse(Console.ReadLine()));

list.Sort();

foreach (int i in list)
    outputBuilder.AppendLine(i.ToString());

Console.Write(outputBuilder.ToString());
