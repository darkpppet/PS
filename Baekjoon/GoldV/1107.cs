using System;
using System.Collections.Generic;
using System.Linq;

string nInput = Console.ReadLine();
int m = int.Parse(Console.ReadLine());
string brokenButtonsInput = Console.ReadLine();
HashSet<int> brokenButtons = brokenButtonsInput == null ? new() : new(Array.ConvertAll(brokenButtonsInput.Split(' '), int.Parse));
HashSet<int> normalButtons = new();
for (int i = 0; i <= 9; i++)
{
	if (!brokenButtons.Contains(i))
		normalButtons.Add(i);
}

char[] nArray = nInput.ToCharArray();
int n = int.Parse(nInput);
int length = nArray.Length;

int[] upper = new int[length];
int[] lower = new int[length];
int[] temp = new int[length];
bool isUpperCheck = false;
bool isLowerCheck = false;
bool checkTemp = true;

int min = Math.Abs(n - 100);

int ArrToInt(int[] arr)
{
	int result = 0;
	
	for (int i = 0; i < arr.Length; i++)
		result = result * 10 + arr[i];
	
	return result;
}

if (normalButtons.Count > 0)
{
	int biggestButton = normalButtons.Max();
	int leastButton = normalButtons.Min();
	
	for (int i = 0; i < length; i++)
	{
		upper[i] = leastButton;
		lower[i] = biggestButton;
	}
	
	for (int i = 1; i < length; i++)
	{
		int[] downBiggest = new int[i];
		for (int j = 0; j < i; j++)
			downBiggest[j] = biggestButton;
		
		min = Math.Min(min, i + n - ArrToInt(downBiggest));
	}
	
	HashSet<int> normalButtonsWithout0 = new(normalButtons);
	normalButtonsWithout0.Remove(0);
	
	if (normalButtonsWithout0.Count > 0)
	{
		int[] upLeast = new int[length + 1];
		upLeast[0] = normalButtonsWithout0.Min();
		for (int i = 1; i <= length; i++)
			upLeast[i] = leastButton;
		
		min = Math.Min(min, length + 1 + ArrToInt(upLeast) - n);
	}
}

for (int i = 0; i < length; i++)
{
	int num = nArray[i] - '0';
	
	for (int j = num + 1; j <= 9; j++)
	{
		if (brokenButtons.Contains(j))
		{
			continue;
		}
		else
		{
			for (int k = 0; k < i; k++)
				upper[k] = temp[k];
			
			upper[i] = j;
			isUpperCheck = true;
			break;
		}
	}
	
	for (int j = num - 1; j >= 0; j--)
	{
		if (brokenButtons.Contains(j))
		{
			continue;
		}
		else
		{	
			for (int k = 0; k < i; k++)
				lower[k] = temp[k];
			
			lower[i] = j;
			isLowerCheck = true;
			break;
		}
	}
	
	if (brokenButtons.Contains(num))
	{
		checkTemp = false;
		break;
	}
	
	temp[i] = num;
}

if (isUpperCheck)
	min = Math.Min(min, length + ArrToInt(upper) - n);

if (isLowerCheck)
	min = Math.Min(min, length + n - ArrToInt(lower));

if (checkTemp)
	min = Math.Min(min, length);

Console.WriteLine(min);
