using System;
using System.Text;
using System.Numerics;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

List<Complex> num1 = new(Array.ConvertAll(input[0].ToCharArray(), x => new Complex(x - '0', 0)));
List<Complex> num2 = new(Array.ConvertAll(input[1].ToCharArray(), x => new Complex(x - '0', 0)));

int length = Math.Max(num1.Count, num2.Count);
int n = (int)Math.Pow(2, Math.Ceiling(Math.Log(length, 2)) + 1);

while (num1.Count < n)
	num1.Insert(0, 0);

while (num2.Count < n)
	num2.Insert(0, 0);

num1.Reverse();
num2.Reverse();

Complex wN = Complex.FromPolarCoordinates(1, 2 * Math.PI / n);

void FFT(List<Complex> num, Complex w)
{
	if (num.Count == 1)
		return;
	
	List<Complex> evenList = new();
	List<Complex> oddList = new();
	for (int i = 0; i < num.Count; i += 2)
	{
		evenList.Add(num[i]);
		oddList.Add(num[i + 1]);
	}
	
	FFT(evenList, w * w);
	FFT(oddList, w * w);
	
	Complex nowW = Complex.One;
	
	for(int i = 0; i < num.Count / 2; i++, nowW *= w)
	{
        num[i] = evenList[i] + nowW * oddList[i];
        num[i + num.Count / 2] = evenList[i] - nowW * oddList[i];
    }
}

FFT(num1, wN);
FFT(num2, wN);

List<Complex> result = new();
for (int i = 0; i < n; i++)
	result.Add(num1[i] * num2[i]);

FFT(result, Complex.Conjugate(wN));

StringBuilder outputBuilder = new();

int before = 0;
foreach (Complex c in result)
{
	before += (int)Math.Round(c.Real) / n;
	outputBuilder.Insert(0, before % 10);
	before /= 10;
}

while (true)
{
	if (outputBuilder[0] == '0')
		outputBuilder.Remove(0, 1);
	else
		break;
}

Console.WriteLine(outputBuilder.Length == 0 ? "0" : outputBuilder.ToString());
