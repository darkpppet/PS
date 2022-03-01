using System;
using System.Text;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(" ");

int pokemonCount = int.Parse(input[0]);
int quizCount = int.Parse(input[1]);

string[] pokeDex = new string[pokemonCount];
Dictionary<string, int> reversePokeDex = new();

for (int i = 0; i < pokemonCount; i++)
{
	pokeDex[i] = Console.ReadLine();
	reversePokeDex[pokeDex[i]] = i + 1;
}

StringBuilder outputBuilder = new();

for (int i = 0; i < quizCount; i++)
{
	string quiz = Console.ReadLine();
	
	if (int.TryParse(quiz, out int index))
		outputBuilder.AppendLine(pokeDex[index - 1]);
	else
		outputBuilder.AppendLine(reversePokeDex[quiz].ToString());
}

Console.Write(outputBuilder.ToString());
