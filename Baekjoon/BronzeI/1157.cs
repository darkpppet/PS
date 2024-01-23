using System;
using System.Linq;

string input = Console.ReadLine().ToUpper();
int[] alphabetCount = Enumerable.Repeat(0, 26).ToArray();

foreach (char c in input)
    alphabetCount[(int)c - 65]++;

if (alphabetCount.Count(x => x == alphabetCount.Max()) > 1)
    Console.WriteLine("?");
else
    Console.WriteLine((char)(Array.IndexOf(alphabetCount, alphabetCount.Max()) + 65));
