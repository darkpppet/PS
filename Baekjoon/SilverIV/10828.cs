using System;
using System.Text;
using System.Collections.Generic;

Stack<int> stack = new();
StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    string order = input.Split(" ")[0];

    switch (order)
    {
        case "push":
            stack.Push(int.Parse(input.Split(" ")[1]));
            break;

        case "pop":
            outputBuilder.AppendLine(stack.Count == 0 ? "-1" : stack.Pop().ToString());
            break;

        case "size":
            outputBuilder.AppendLine(stack.Count.ToString());
            break;

        case "empty":
            outputBuilder.AppendLine(stack.Count == 0 ? "1" : "0");
            break;

        case "top":
            outputBuilder.AppendLine(stack.Count == 0 ? "-1" : stack.Peek().ToString());
            break;
    }
}

Console.WriteLine(outputBuilder.ToString());
