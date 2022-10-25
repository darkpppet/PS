using System;

int n = int.Parse(Console.ReadLine());

int count = -1;

for (int i = n / 5; i >= 0; i--)
{
    int r = n - i * 5;
    if (r % 3 == 0)
    {
        count = i + r / 3;
        break;
    }
}

Console.WriteLine(count);
