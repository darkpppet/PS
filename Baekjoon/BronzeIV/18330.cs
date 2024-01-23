using System;

int n = int.Parse(Console.ReadLine());
int k = int.Parse(Console.ReadLine());

Console.WriteLine(k + 60 >= n ? n * 1500 : n * 3000 - (k + 60) * 1500);
