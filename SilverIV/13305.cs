using System;
using System.Collections.Generic;
using System.Linq;

int n = int.Parse(Console.ReadLine()) - 1;

List<long> lengths = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
List<long> prices = Console.ReadLine().Split(' ').SkipLast(1).Select(long.Parse).ToList();

long result = prices[0] * lengths[0];

int minPriceIndex = 0; 

for (int i = 1; i < n; i++)
{
    if (prices[i] < prices[minPriceIndex])
        minPriceIndex = i;
    
    result += prices[minPriceIndex] * lengths[i];
}

Console.WriteLine(result);
