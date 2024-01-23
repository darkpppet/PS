using System;

string[] input = Console.ReadLine().Split(" ");

double n1 = double.Parse(input[0]);
double n2 = double.Parse(input[1]);
double n3 = double.Parse(input[2]);

int result1 = (int)(n1 * n2 / n3);
int result2 = (int)(n1 * n3 / n2);

Console.WriteLine(result1 > result2 ? result1 : result2);
