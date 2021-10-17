using System;

int n = int.Parse(Console.ReadLine());
int count = 0;

for (int i = 0; ; i++)
{
    count += i.ToString().Contains("666") ? 1 : 0;

    if (count == n)
    {
        Console.WriteLine(i);
        break;
    }
}
