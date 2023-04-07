using System;
using System.Collections.Generic;
using System.Linq;

List<char> input = Console.ReadLine().ToCharArray().ToList();
List<char> inputX10000 = new(input);

for (int i = 0; i < 4; i++)
{
	input.Insert(0, '0');
	inputX10000.Add('0');
}

List<char> sumList = new();
int before = 0;

for (int i = 1; i <= input.Count; i++)
{
	int sum = input[^i] + inputX10000[^i] + before - 2 * '0';
	
	sumList.Insert(0, sum % 2 == 0 ? '0' : '1');
	before = sum <= 1 ? 0 : 1;
}

if (before == 1)
	sumList.Insert(0, '1');

Console.WriteLine(new string(sumList.ToArray()));
