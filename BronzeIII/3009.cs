using System;
using System.Linq;

(int Xpos, int Ypos)[] poses = new (int Xpos, int Ypos)[3];

for (int i = 0; i < 3; i++)
{
	string[] inputPoses = Console.ReadLine().Split(" ");
	poses[i] = (int.Parse(inputPoses[0]), int.Parse(inputPoses[1]));
}

foreach ((int Xpos, int _) in poses)
{
	if (poses.Count(x => x.Xpos == Xpos) == 1)
	{
		Console.Write(Xpos);
		break;
	}
}

Console.Write(" ");

foreach ((int _, int Ypos) in poses)
{
	if (poses.Count(x => x.Ypos == Ypos) == 1)
	{
		Console.Write(Ypos);
		break;
	}
}
