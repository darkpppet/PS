using System;

int[] bessiePos = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] daisyPos = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] johnPos = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

int bessieTime = Math.Max(Math.Abs(johnPos[0] - bessiePos[0]), Math.Abs(johnPos[1] - bessiePos[1]));
int daisyTime = Math.Abs(johnPos[0] - daisyPos[0]) + Math.Abs(johnPos[1] - daisyPos[1]);

if (bessieTime == daisyTime)
	Console.WriteLine("tie");
else
	Console.WriteLine(bessieTime < daisyTime ? "bessie" : "daisy");
