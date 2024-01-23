System.Console.WriteLine((int.Parse(System.Console.ReadLine()) % 8) switch
						 {
							 1 => 1,
							 0 or 2 => 2,
							 3 or 7 => 3,
							 4 or 6 => 4,
							 5 => 5,
							 _ => 0
						 });
