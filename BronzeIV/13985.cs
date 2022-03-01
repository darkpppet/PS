using System;

string[] input = Console.ReadLine().Replace(" ", "").Split(new[] { '+', '=' });

int a = int.Parse(input[0]);
int b = int.Parse(input[1]);
int c = int.Parse(input[2]);

Console.WriteLine(a + b == c ? "YES" : "NO");
