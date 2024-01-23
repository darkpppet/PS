using System;
using System.Text;
using System.Collections.Generic;

Queue<int> queue = new();
StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    string order = input.Split(" ")[0];

    switch (order)
    {
        case "push":
            queue.Enqueue(int.Parse(input.Split(" ")[1]));
            break;

        case "pop":
            outputBuilder.AppendLine(queue.Count == 0 ? "-1" : queue.Dequeue().ToString());
            break;

        case "size":
            outputBuilder.AppendLine(queue.Count.ToString());
            break;

        case "empty":
            outputBuilder.AppendLine(queue.Count == 0 ? "1" : "0");
            break;

        case "front":
            outputBuilder.AppendLine(queue.Count == 0 ? "-1" : queue.Peek().ToString());
            break;

        case "back":
            outputBuilder.AppendLine(queue.Count == 0 ? "-1" : queue.ToArray()[^1].ToString());
            break;
    }
}

Console.WriteLine(outputBuilder.ToString());
