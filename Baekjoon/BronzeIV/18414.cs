using System;

string[] input = Console.ReadLine().Split(' ');

int x = int.Parse(input[0]);
int l = int.Parse(input[1]);
int r = int.Parse(input[2]);

Console.WriteLine(x switch
				  {
					  int when x >= l && x <= r => x,
					  int when x < l => l,
					  int when x > r => r
				  });
