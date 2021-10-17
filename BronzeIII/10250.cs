using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    int h = int.Parse(input.Split(" ")[0]);
    int n = int.Parse(input.Split(" ")[2]);

    Console.WriteLine("{0}{1:D2}", n % h == 0 ? h : n % h, n / h + (n % h == 0 ? 0 : 1));
}
