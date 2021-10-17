using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();

    int reaptcount = int.Parse(input.Split(' ')[0]);
    string str = input.Split(' ')[1];

    string output = "";

    foreach (char c in str)
    {
        for (int j = 0; j < reaptcount; j++)
            output += c;
    }

    Console.WriteLine(output);
}
