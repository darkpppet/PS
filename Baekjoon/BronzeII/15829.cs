using System;
using System.Linq;
using System.Numerics;

Console.ReadLine();
string str = Console.ReadLine();

Console.WriteLine(str.Select((item, index) => (item - 'a' + 1) * BigInteger.Pow(31, index)).Aggregate(BigInteger.Add) % 1234567891);
