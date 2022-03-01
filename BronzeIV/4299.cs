string[] input = System.Console.ReadLine().Split(" ");

int sum = int.Parse(input[0]);
int diff = int.Parse(input[1]);

System.Console.WriteLine(sum < diff || sum % 2 != diff % 2 ? -1 : $"{(sum + diff) / 2} {(sum - diff) / 2}");
