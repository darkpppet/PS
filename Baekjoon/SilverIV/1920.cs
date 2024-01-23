using System;
using System.Text;

Console.ReadLine();
int[] aArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
Console.ReadLine();
int[] mArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

Array.Sort(aArr);

StringBuilder outputBuilder = new();

foreach (int m in mArr)
    outputBuilder.AppendLine(Array.BinarySearch(aArr, m) < 0 ? "0" : "1");

Console.WriteLine(outputBuilder.ToString());
