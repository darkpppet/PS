using System;

int count = int.Parse(Console.ReadLine());

int[] numbers = Array.ConvertAll(Console.ReadLine().Split(" "), x => int.Parse(x));

int primeCount = 0;

foreach (int i in numbers)
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

    primeCount += isPrime ? 1 : 0;
}

Console.WriteLine(primeCount);
