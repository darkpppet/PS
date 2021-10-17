using System;
using System.Text;
using System.Collections.Generic;

Dictionary<int, int> dictionary = new();
StringBuilder outputBuilder = new();

Console.ReadLine();
int[] cards = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

foreach (int card in cards)
{
    if (dictionary.ContainsKey(card))
        dictionary[card]++;
    else
        dictionary[card] = 1;
}

Console.ReadLine();
int[] numbers = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));
foreach (int number in numbers)
{
    outputBuilder.Append(dictionary.ContainsKey(number) ? 0 : dictionary[number]);
    outputBuilder.Append(' ');
}

Console.WriteLine(outputBuilder.ToString());
