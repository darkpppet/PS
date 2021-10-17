using System;
using System.Collections.Generic;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    int n = int.Parse(input.Split(" ")[0]);
    int index = int.Parse(input.Split(" ")[1]);

    int[] queue = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

    int dequeueCount = 0;


}