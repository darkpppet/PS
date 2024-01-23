using System;

string input = Console.ReadLine();

int n = int.Parse(input.Split(" ")[0]);
int m = int.Parse(input.Split(" ")[1]);

int[] cards = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

int max = 0;

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (j == i)
            continue;

        for (int k = 0; k < n; k++)
        {
            if (k == i || k == j)
                continue;

            int sum = cards[i] + cards[j] + cards[k];

            if (sum <= m)
                max = sum > max ? sum : max;
        }
    }
}

Console.WriteLine(max);
