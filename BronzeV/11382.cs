using System;
using System.Numerics;

BigInteger[] numbers = Array.ConvertAll(Console.ReadLine().Split(" "), BigInteger.Parse);

Console.WriteLine(numbers[0] + numbers[1] + numbers[2]);
