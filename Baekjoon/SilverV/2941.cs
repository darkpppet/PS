using System;

string input = Console.ReadLine();

while (true)
{
	if (input.Contains("c="))
		input = input.Replace("c=", "1");
	else if (input.Contains("c-"))
		input = input.Replace("c-", "2");
	else if (input.Contains("dz="))
		input = input.Replace("dz=", "3");
	else if (input.Contains("d-"))
		input = input.Replace("d-", "4");
	else if (input.Contains("lj"))
		input = input.Replace("lj", "5");
	else if (input.Contains("nj"))
		input = input.Replace("nj", "6");
	else if (input.Contains("s="))
		input = input.Replace("s=", "7");
	else if (input.Contains("z="))
		input = input.Replace("z=", "8");
	else
		break;
}

Console.WriteLine(input.Length);
