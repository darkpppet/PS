using System;

string[] inputArr = Console.ReadLine().Split(" ");

int a = int.Parse(inputArr[0]);
int b = int.Parse(inputArr[1]);
int c = int.Parse(inputArr[2]);

Console.WriteLine(b < c ? a / (c - b) + 1 : -1);
