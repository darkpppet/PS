using System;

string[] input = Console.ReadLine().Split(' ');

double a = double.Parse(input[0]);
double b = double.Parse(input[1]);
double c = double.Parse(input[2]);

double beforeResult = 0;
double result = c / (a + b);

while ($"{result:F8}" != $"{beforeResult:F8}")
{
	beforeResult = result;
	result = (c + b * result * Math.Cos(result) - b * Math.Sin(result)) / (a + b * Math.Cos(result));
}

Console.WriteLine(result);
