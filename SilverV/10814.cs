using System;
using System.Text;
using System.Collections.Generic;

List<(int Age, string Name, int Order)> list = new();
StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    list.Add((int.Parse(input.Split(" ")[0]), input.Split(" ")[1], i));
}

list.Sort((a, b) =>
{
    if (a.Age == b.Age)
        return a.Order < b.Order ? -1 : 1;
    else
        return a.Age < b.Age ? -1 : 1;
});

foreach ((int Age, string Name, int _) in list)
{
    outputBuilder.Append(Age);
    outputBuilder.Append(' ');
    outputBuilder.AppendLine(Name);
}

Console.Write(outputBuilder.ToString());
