using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

List<(int R, int G, int B)> costList = new();

for (int i = 0; i < n; i++)
{
    string[] input = Console.ReadLine().Split(' ');
    
    costList.Add((int.Parse(input[0]), int.Parse(input[1]), int.Parse(input[2])));
}

List<(int R, int G, int B)> minCostList = new() { (costList[0].R, costList[0].G, costList[0].B) };

for (int i = 1; i < n; i++)
{
    (int R, int G, int B) tempTuple;
    
    tempTuple.R = Math.Min(costList[i].R + minCostList[i - 1].G, costList[i].R + minCostList[i - 1].B);
    tempTuple.G = Math.Min(costList[i].G + minCostList[i - 1].R, costList[i].G + minCostList[i - 1].B);
    tempTuple.B = Math.Min(costList[i].B + minCostList[i - 1].R, costList[i].B + minCostList[i - 1].G);
    
    minCostList.Add(tempTuple);
}

(int lastR, int lastG, int lastB) = minCostList[n - 1];

Console.WriteLine(Math.Min(Math.Min(lastR, lastG), lastB));
