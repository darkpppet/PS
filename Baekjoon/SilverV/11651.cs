using System;
using System.Text;
using System.Collections.Generic;

StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

List<(int Xpos, int Ypos)> list = new();

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    list.Add((int.Parse(input.Split(" ")[0]), int.Parse(input.Split(" ")[1])));
}

list.Sort((a, b) =>
{
    if (a.Ypos == b.Ypos)
        return a.Xpos < b.Xpos ? -1 : 1;
    else
        return a.Ypos < b.Ypos ? -1 : 1;
});

foreach ((int Xpos, int Ypos) in list)
{
    outputBuilder.Append(Xpos);
    outputBuilder.Append(' ');
    outputBuilder.Append(Ypos);
    outputBuilder.AppendLine();
}

Console.WriteLine(outputBuilder.ToString());
