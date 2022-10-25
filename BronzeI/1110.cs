using System;

int n = int.Parse(Console.ReadLine());
int originn = n;
int cycle = 0;

do
{
    cycle++;
    n = ((n / 10) + (n % 10)) % 10 + ((n % 10) * 10);
} while (n != originn);

Console.WriteLine(cycle);
