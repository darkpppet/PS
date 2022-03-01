using System;

while (true)
{
    string input = Console.ReadLine();

    if (input == null)
        break;

    int a = int.Parse(input.Split(' ')[0]);
    int b = int.Parse(input.Split(' ')[1]);

    Console.WriteLine(a + b);
}
