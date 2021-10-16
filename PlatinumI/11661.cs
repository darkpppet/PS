using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int a = int.Parse(input[0]);
int b = int.Parse(input[1]);
int c = -int.Parse(input[2]);
int x1 = int.Parse(input[3]);
int x2 = int.Parse(input[4]);
int y1 = int.Parse(input[5]);
int y2 = int.Parse(input[6]);

if (a < b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
	
	temp = x1;
	x1 = y1;
	y1 = temp;
	
	temp = x2;
	x2 = y2;
	y2 = temp;
}

(int A, int B) gcd = (a, b);

while (gcd.B != 0)
	gcd = (gcd.B, gcd.A % gcd.B);

int d = gcd.A;

if (c % d == 0)
{
	int CalcQ(int i) => (int)Math.Floor(CalcR(i - 1) / CalcR(i));
	
	Dictionary<int, int> memoR = new()
	{
		[0] = a,
		[1] = b
	};
	
	int CalcR(int i)
	{
		if (!memoR.ContainsKey(i))
			memoR[i] = CalcR(i - 2) % CalcR(i - 1);
		
		return memoR[i];
	}
	
	Dictionary<int, int> memoX = new()
	{
		[0] = 1,
		[1] = 0
	};
	
	int CalcX(int i)
	{
		if (!memoX.ContainsKey(i))
			memoX[i] = CalcX(i - 2) - CalcX(i - 1) * CalcQ(i);
		
		return memoX[i];
	}
	
	Dictionary<int, int> memoY = new()
	{
		[0] = 0,
		[1] = 1
	};
	
	
	int CalcY(int i)
	{
		if (!memoY.ContainsKey(i))
			memoY[i] = CalcY(i - 2) - CalcY(i - 1) * CalcQ(i);
		
		return memoY[i];
	}
	
	int r = a;  
	int i = 0;
	
	for (; r > 0; i++, r = CalcR(i));
	
	int specialX = CalcX(i - 1) * c / d;
	int specialY = CalcY(i - 1) * c / d;
	
	int coefX = b / d;
	int coefY = a / d;
	
	int leftX = Math.Min((x1 - specialX) / coefX, (x2 - specialX) / coefX);
	int rightX = Math.Max((x1 - specialX) / coefX, (x2 - specialX) / coefX);
	int leftY = Math.Min((specialY - y1) / coefY, (specialY - y2) / coefY);
	int rightY = Math.Max((specialY - y1) / coefY, (specialY - y2) / coefY);
	
	int left = Math.Max(leftX, leftY);
	int right = Math.Min(rightX, rightY);
	
	Console.WriteLine(right - left + 1 > 0 ? right - left + 1 : 0);
}
else
{
	Console.WriteLine(0);
}
