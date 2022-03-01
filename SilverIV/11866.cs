using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

StringBuilder outputBuilder = new();
outputBuilder.Append('<');

string input = Console.ReadLine();

int n = int.Parse(input.Split(" ")[0]);
int k = int.Parse(input.Split(" ")[1]);

List<int> table = Enumerable.Range(1, n).ToList();

int index = 0;

while (table.Count > 0)
{
    index += k - 1;

    while (index > table.Count - 1)
        index -= table.Count;

    outputBuilder.Append(table[index]);
    if (table.Count > 1)
        outputBuilder.Append(", ");

    table.RemoveAt(index);
}

outputBuilder.Append('>');

Console.WriteLine(outputBuilder.ToString());
