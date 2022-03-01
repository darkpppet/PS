using System;
using System.Linq;

string input = Console.ReadLine();
string[] groups = input.Split("-");

int result = Array.ConvertAll(groups[0].Split("+"), int.Parse).Sum() * (input.ToCharArray()[0] == '-' ? -1 : 1); 

for (int i = 1; i < groups.Length; i++)
	result -= Array.ConvertAll(groups[i].Split("+"), int.Parse).Sum();

Console.WriteLine(result);
