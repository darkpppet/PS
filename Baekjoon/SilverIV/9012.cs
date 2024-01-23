using System;

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    bool isNo = false;

    while (true)
    {
        if (input.Contains("()"))
        {
            input = input.Replace("()", "");
        }
        else
        {
            if (input.Length != 0)
                isNo = true;
            break;
        }
    }

    Console.WriteLine(isNo ? "NO" : "YES");
}
