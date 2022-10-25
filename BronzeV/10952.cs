using System;

while (true)
{
    string input = Console.ReadLine();

    int a = int.Parse(input.Split(' ')[0]);
    int b = int.Parse(input.Split(' ')[1]);

    if (a == 0 && b == 0)
        break;

    Console.WriteLine(a + b);
}
