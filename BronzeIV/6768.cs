int j = int.Parse(System.Console.ReadLine());

System.Console.WriteLine(j < 4 ? 0 : (j - 1) * (j - 2) * (j - 3) / 6);
