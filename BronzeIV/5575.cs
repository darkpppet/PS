for (int i = 0; i < 3; i++)
{
	int[] arr = System.Array.ConvertAll(System.Console.ReadLine().Split(" "), int.Parse);
	(int Hour, int Minute, int Second) tuple = (arr[3] - arr[0], arr[4] - arr[1], arr[5] - arr[2]);
	
	if (tuple.Second < 0)
	{
		tuple.Second += 60;
		tuple.Minute -= 1;
	}
	
	if (tuple.Minute < 0)
	{
		tuple.Minute += 60;
		tuple.Hour -= 1;
	}
	
	System.Console.WriteLine($"{tuple.Hour} {tuple.Minute} {tuple.Second}");
}
