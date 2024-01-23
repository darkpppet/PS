using System;
using System.Collections.Generic;

List<int> depthList = new();

for (int i = 0; i < 4; i++)
	depthList.Add(int.Parse(Console.ReadLine()));

if (depthList[0] == depthList[1] && depthList[1] == depthList[2] && depthList[2] == depthList[3])
	Console.WriteLine("Fish At Constant Depth");
else if (depthList[0] < depthList[1] && depthList[1] < depthList[2] && depthList[2] < depthList[3])
	Console.WriteLine("Fish Rising");
else if (depthList[0] > depthList[1] && depthList[1] > depthList[2] && depthList[2] > depthList[3])
	Console.WriteLine("Fish Diving");
else
	Console.WriteLine("No Fish");
