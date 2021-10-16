using System;

int n = int.Parse(Console.ReadLine());

Console.WriteLine(n switch
				  {
					  int when n % 4 == 0 => 2,
					  int when n % 2 == 0 => 1,
					  _ => 0
				  });
