using System;
using System.Collections.Generic;
using System.Linq;

int t = int.Parse(Console.ReadLine());

for (int testCount = 0; testCount < t; testCount++)
{
    int n = int.Parse(Console.ReadLine());
    
    int[] top = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
    int[] bottom = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
    
    List<(int Top, int Bottom, int No)> pointMaxList = new() { (top[0], bottom[0], 0) };
    
    for (int i = 1; i < n; i++)
    {
        (int Top, int Bottom, int No) tempTuple;
        
        tempTuple.Top = Math.Max(top[i] + pointMaxList[i - 1].Bottom, top[i] + pointMaxList[i - 1].No);
        tempTuple.Bottom = Math.Max(bottom[i] + pointMaxList[i - 1].Top, bottom[i] + pointMaxList[i - 1].No);
        tempTuple.No = Math.Max(pointMaxList[i - 1].Top, pointMaxList[i - 1].Bottom);
        
        pointMaxList.Add(tempTuple);
    }
    
    (int lastTop, int lastBottom, int lastNo) = pointMaxList[n - 1];
    
    Console.WriteLine(Math.Max(Math.Max(lastTop, lastBottom), lastNo));
}
