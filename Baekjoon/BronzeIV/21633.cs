using System;

double k = double.Parse(Console.ReadLine());

double result = 25 + k * 0.01;

if (result < 100)
	result = 100;
else if (result > 2000)
	result = 2000;

Console.WriteLine(result);
