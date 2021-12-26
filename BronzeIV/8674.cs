using System;

string[] inputs = Console.ReadLine().Split(' ');

(long V, long H) = (long.Parse(inputs[0]), long.Parse(inputs[1]));

if (V % 2 == 0 || H % 2 == 0)
    Console.WriteLine(0);
else
    Console.WriteLine(Math.Min(V, H));
