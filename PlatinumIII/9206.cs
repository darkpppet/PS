using System;
using System.Linq;

string[] input = Console.ReadLine().Split(' ');

double v = double.Parse(input[0]);
int n = int.Parse(input[1]);

double[] diff = new double[n];

for (int count = 0; count < n; count++)
{
	input = Console.ReadLine().Split(' ');
	
	double a = double.Parse(input[0]);
	double b = double.Parse(input[1]);
	double h = double.Parse(input[2]);
	
	double F(double x) => Math.Pow(a * Math.Pow(Math.E, -(x * x)) + b * Math.Sqrt(x), 2);
	
	double tempV = 0;
	
	for (double i = 0; i < 100000; i++)
	{
		double left = h * i / 100000;
		double right = h * (i + 1) / 100000;
		
		tempV += (right - left) * (F(left) + 4 * F((left + right) / 2) + F(right)) / 6;
	}
	
	tempV *= Math.PI;
	
	diff[count] = Math.Abs(v - tempV);
}

Console.WriteLine(Array.IndexOf(diff, diff.Min()));
