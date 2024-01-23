string[] input = System.Console.ReadLine().Split(" ");

long a = long.Parse(input[0]);
long b = long.Parse(input[1]);

System.Console.WriteLine((a + b) * (a - b));
