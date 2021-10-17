using System;
using System.Text;

string input = Console.ReadLine();

int min = int.Parse(input.Split(" ")[0]);
int max = int.Parse(input.Split(" ")[1]);

StringBuilder outputBuilder = new();


for (int i = min; i <= max; i++)
{
    int sqrtNum = (int)Math.Sqrt(i);
    bool isPrime = true;

    for (int j = 2; j <= sqrtNum; j++)
    {
        if (i % j == 0)
        {
            isPrime = false;
            break;
        }
    }

    isPrime = i == 1 ? false : isPrime;

    if (isPrime)
        outputBuilder.AppendLine(i.ToString());
}

Console.Write(outputBuilder.ToString());
