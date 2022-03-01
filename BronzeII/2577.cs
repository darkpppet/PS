using System;
using System.Linq;

int a = int.Parse(Console.ReadLine());
int b = int.Parse(Console.ReadLine());
int c = int.Parse(Console.ReadLine());

string product = (a * b * c).ToString();

for (int i = 0; i <= 9; i++)
    Console.WriteLine(product.Count(x => x == char.Parse(i.ToString())));
