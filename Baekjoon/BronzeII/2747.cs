int Fibonacci(int i) => i switch
{
	0 => 0,
	1 => 1,
	2 => 1,
	3 => 2,
	4 => 3,
	5 => 5,
	6 => 8,
	7 => 13,
	8 => 21,
	_ => Fibonacci(i - 1) + Fibonacci(i - 2)
};

System.Console.WriteLine(Fibonacci(int.Parse(System.Console.ReadLine())));
