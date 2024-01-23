using System;
using System.Text;
using System.Linq;

int count = int.Parse(Console.ReadLine());

bool[] ziphap = Enumerable.Repeat<bool>(false, 20).ToArray<bool>();
bool[] allZiphap = Enumerable.Repeat<bool>(true, 20).ToArray<bool>();
bool[] emptyZiphap = Enumerable.Repeat<bool>(false, 20).ToArray<bool>();

StringBuilder outputBuilder = new();

for (int i = 0; i < count; i++)
{
	string[] input = Console.ReadLine().Split(" ");
	
	switch (input[0])
	{
		case "add":
			ziphap[int.Parse(input[1]) - 1] = true;
			break;
			
		case "remove":
			ziphap[int.Parse(input[1]) - 1] = false;
			break;
			
		case "check":
			outputBuilder.AppendLine(ziphap[int.Parse(input[1]) - 1] ? "1" : "0");
			break;
			
		case "toggle":
			ziphap[int.Parse(input[1]) - 1] = !ziphap[int.Parse(input[1]) - 1];
			break;
			
		case "all":
			Array.Copy(allZiphap, ziphap, 20);
			break;
			
		case "empty":
			Array.Copy(emptyZiphap, ziphap, 20);
			break;
	}
}

Console.Write(outputBuilder.ToString());
