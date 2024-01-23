using System;

string[] input = Console.ReadLine().Split(' ');

int a = int.Parse(input[0]);
int b = int.Parse(input[1]);
int c = int.Parse(input[2]);

if (a == b || a == c || b == c || a + b == c || a + c == b || b + c == a)
    Console.WriteLine('S');
else
    Console.WriteLine('N');
