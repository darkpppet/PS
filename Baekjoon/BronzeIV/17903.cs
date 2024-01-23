System.Console.WriteLine(int.Parse(System.Console.ReadLine().Split(' ')[0]) switch
						 {
							 < 8 => "unsatisfactory",
							 _ => "satisfactory"
						 });
