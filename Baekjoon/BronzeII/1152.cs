using System;

string input = Console.ReadLine().Trim(' ');

Console.WriteLine(input == "" ? 0 : input.Split(' ').Length);
