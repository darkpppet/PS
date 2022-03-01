using System;
using System.Text;
using System.Collections.Generic;

int t = int.Parse(Console.ReadLine());

Dictionary<int, (int BeforeNum, char BeforeCalc)> history = new();

for (int i = 0; i < t; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
	
	history.Clear();
	history[a] = (a, '\0');

	List<int> beforeList = new() { a };
	
	while (!history.ContainsKey(b))
	{
		List<int> tempList = new();
		
		foreach (int num in beforeList)
		{
			int d = (2 * num) % 10000;
			int s = (num + 9999) % 10000;
			int l = (num / 1000 + 10 * num) % 10000;
			int r = 1000 * (num % 10) + num / 10;
			
			if (!history.ContainsKey(d))
			{
				history[d] = (num, 'D');
				tempList.Add(d);
			}
			
			if (!history.ContainsKey(s))
			{
				history[s] = (num, 'S');
				tempList.Add(s);
			}
			
			if (!history.ContainsKey(l))
			{
				history[l] = (num, 'L');
				tempList.Add(l);
			}
			
			if (!history.ContainsKey(r))
			{
				history[r] = (num, 'R');
				tempList.Add(r);
			}
		}
		
		beforeList = new(tempList);
	}
	
	StringBuilder outputBuilder = new();
	for (int before = b; before != a; before = history[before].BeforeNum)
		outputBuilder.Insert(0, history[before].BeforeCalc);
	Console.WriteLine(outputBuilder.ToString());
}
