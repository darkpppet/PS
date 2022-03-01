char[] input = System.Console.ReadLine().ToCharArray();

System.Console.WriteLine(input.Length switch
						 {
							 2 => input[0] + input[1] - 2 * '0',
							 3 => 10 + (input[2] == '0' ? input[0] : input[2]) - '0',
							 _ => 20
						 });
