string[] input = System.Console.ReadLine().Split(" ");

long n = long.Parse(input[0]);
long m = long.Parse(input[1]);

System.Console.WriteLine(n % 2 != 0 && m % 2 != 0 ? (n * m - 1) / 2 : n * m / 2);
