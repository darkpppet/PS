using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    int score = 0;
    int ocount = 0;

    for (int j = 0; j < input.Length; j++)
    {
        switch (input[j])
        {
            case 'O':
                score += ++ocount;
                break;

            case 'X':
                ocount = 0;
                break;
        }
    }

    Console.WriteLine(score);
}