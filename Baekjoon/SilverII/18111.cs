using System;
using System.Linq;

string input = Console.ReadLine();

int n = int.Parse(input.Split(" ")[0]);
int m = int.Parse(input.Split(" ")[1]);
int b = int.Parse(input.Split(" ")[2]);

int[,] map = new int[m, n];

int time = 0;

while (map.Min()

