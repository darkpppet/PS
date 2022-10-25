using System;

string input = Console.ReadLine();

int n = int.Parse(input.Split(" ")[0]);
int k = int.Parse(input.Split(" ")[1]);

int result = 1;

for (int i = n; i > (n - k); i--)
    result *= i;

for (int i = k; i > 0; i--)
    result /= i;

Console.WriteLine(result);
