using System;
using System.Text;
using System.Collections.Generic;

StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

List<short> list = new();

for (int i = 0; i < count; i++)
    list.Add(short.Parse(Console.ReadLine()));

list.Sort();

for (int i = 0; i < count; i++)
{
    outputBuilder.AppendLine(list[i].ToString());
    if (i % 800 == 0)
    {
        Console.Write(outputBuilder.ToString());
        outputBuilder.Clear();
    }
}
