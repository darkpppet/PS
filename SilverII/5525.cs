using System;

int n = int.Parse(Console.ReadLine());
int k = int.Parse(Console.ReadLine());
char[] input = Console.ReadLine().ToCharArray();

int pnLength = 1 + 2 * n;
char[] pn = { 'I', 'O' };

int FailFunc(int x) => x > 0 ? x - 1 : 0;

int begin = 0;
int m = 0;
int count = 0;

while (begin <= k - pnLength)
{
	bool isSame = true;
	
	for (; m < pnLength; m++)
	{
		if (pn[m % 2] != input[begin + m])
		{
			isSame = false;
			break;
		}
	}
	
	begin += m == 0 ? 1 : m - FailFunc(m - 1);
	m = FailFunc(m - 1);
	
	if (isSame)
		count++;
}

Console.WriteLine(count);
