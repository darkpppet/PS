using System;
using System.Linq;

string input;

while (true)
{
    input = Console.ReadLine();

    if (input == ".")
        break;

    input = new(input.Where(x => x == '[' || x == ']' || x == '(' || x == ')').ToArray());

    while (input.Contains("()") || input.Contains("[]"))
    {
        input = input.Replace("()", "");
        input = input.Replace("[]", "");
    }

    Console.WriteLine(input == "" ? "yes" : "no");
}
