using System;
using System.Text;

int count = int.Parse(Console.ReadLine());
(int Xpos, int Ypos)[] poses = new (int, int)[count];

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    poses[i].Xpos = int.Parse(input.Split(" ")[0]);
    poses[i].Ypos = int.Parse(input.Split(" ")[1]);
}

Array.Sort(poses, (a, b) =>
{
    if (a.Xpos == b.Xpos)
        return a.Ypos < b.Ypos ? -1 : 1;
    else
        return a.Xpos < b.Xpos ? -1 : 1;
});

StringBuilder outputBuilder = new();

foreach ((int Xpos, int Ypos) in poses)
{
    outputBuilder.Append(Xpos);
    outputBuilder.Append(' ');
    outputBuilder.Append(Ypos);
    outputBuilder.AppendLine();
}

Console.WriteLine(outputBuilder.ToString());
