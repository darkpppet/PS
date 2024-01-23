using System;
using System.Numerics;

string[] input = Console.ReadLine().Split(" ");

BigInteger n = BigInteger.Parse(input[0]);
BigInteger m = BigInteger.Parse(input[1]);

Console.WriteLine(n / m + " " + n % m);
