using System;

int n = int.Parse(Console.ReadLine());
n += 4;
n /= 6;

int result;

for (int i = 2; ; i++)
{
    if (n == 0)
    {
        result = 1;
        break;
    }
    else if (n > (i - 1) * (i - 2) / 2 && n <= i * (i - 1) / 2)
    {
        result = i;
        break;
    }
}

Console.WriteLine(result);
