using System;
using System.Linq;

while (true)
{
    string input = Console.ReadLine();

    if (input == "0")
        break;

    Console.WriteLine(input == new string(input.Reverse().ToArray()) ? "yes" : "no");
}
