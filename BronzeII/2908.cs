using System;
using System.Linq;

string[] numbers = Console.ReadLine().Split(' ');

numbers[0] = new string(numbers[0].Reverse().ToArray());
numbers[1] = new string(numbers[1].Reverse().ToArray());

Console.WriteLine(int.Parse(numbers[0]) > int.Parse(numbers[1]) ? numbers[0] : numbers[1]);
