using System;
using System.Linq;

int[] input = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

Console.WriteLine(input.Sum() < 100 ? Array.IndexOf(input, input.Min()) switch
				  {
					  0 => "Soongsil",
					  1 => "Korea",
					  2 => "Hanyang",
					  _ => ""
				  } : "OK");
