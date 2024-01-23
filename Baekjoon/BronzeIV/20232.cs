System.Console.WriteLine(int.Parse(System.Console.ReadLine()) switch
						 {
							 2006 => "PetrSU, ITMO",
							 1996 or 1997 or 2000 or 2007 or 2008 or 2013 or 2018 => "SPbSU",
							 _ => "ITMO"
						 });
