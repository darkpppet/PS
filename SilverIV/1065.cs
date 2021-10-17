using System;

bool IsHansu(int n)
{
    if (n < 100)
        return true;

    if (n == 1000)
        return false;

    if (n.ToString()[0] - n.ToString()[1] == n.ToString()[1] - n.ToString()[2])
        return true;
    else
        return false;
}

int count = int.Parse(Console.ReadLine());
int hansuCount = 0;

for (int i = 1; i <= count; i++)
{
    if (IsHansu(i))
        hansuCount++;
}

Console.WriteLine(hansuCount);
