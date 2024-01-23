using System;
using System.Collections.Generic;
using System.Linq;

List<string> wordList = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
    wordList.Add(Console.ReadLine());

wordList = wordList.Distinct().ToList();

wordList.Sort((x, y) =>
{
    if (x.Length == y.Length)
        return string.Compare(x, y);
    else
        return x.Length < y.Length ? -1 : 1;
});

foreach (string word in wordList)
    Console.WriteLine(word);
