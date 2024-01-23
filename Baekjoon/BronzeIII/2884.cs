using System;

string input = Console.ReadLine();

int h = int.Parse(input.Split(' ')[0]);
int m = int.Parse(input.Split(' ')[1]);

m -= 45;

if (m < 0)
{
    h -= 1;
    m += 60;
}

if (h < 0)
    h += 24;

Console.WriteLine(h + " " + m);
