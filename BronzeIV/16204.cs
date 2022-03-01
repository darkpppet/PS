string[] input = System.Console.ReadLine().Split(" ");

int n = int.Parse(input[0]);
int m = int.Parse(input[1]);
int k = int.Parse(input[2]);

System.Console.WriteLine(n - System.Math.Abs(m - k));
