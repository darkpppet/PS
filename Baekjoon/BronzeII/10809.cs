using System;
using System.Linq;

string input = Console.ReadLine();
int[] alphabetCount = Enumerable.Repeat(-1, 26).ToArray();

for (int i = 0; i < input.Length; i++)
{
    if (alphabetCount[input[i] - 97] == -1)
        alphabetCount[input[i] - 97] = i;
}

foreach (int i in alphabetCount)
    Console.Write(i + " ");
