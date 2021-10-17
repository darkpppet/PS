using System;

string input = Console.ReadLine();

int a = int.Parse(input.Split(" ")[0]) > int.Parse(input.Split(" ")[1]) ? int.Parse(input.Split(" ")[0]) : int.Parse(input.Split(" ")[1]);
int b = int.Parse(input.Split(" ")[0]) < int.Parse(input.Split(" ")[1]) ? int.Parse(input.Split(" ")[0]) : int.Parse(input.Split(" ")[1]);

int product = a * b;
int r = a % b;

while (r != 0)
{
    a = b;
    b = r;
    r = a % b;
}

Console.WriteLine(b);
Console.WriteLine(product / b);
