using System;
using System.Text;
using System.Collections.Generic;

List<int> list = new();
StringBuilder outputBuilder = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    string input = Console.ReadLine();
    string order = input.Split(" ")[0];
    int number;

    switch (order)
    {
        case "push_front":
            number = int.Parse(input.Split(" ")[1]);
            list.Insert(0, number);
            break;

        case "push_back":
            number = int.Parse(input.Split(" ")[1]);
            list.Add(number);
            break;

        case "pop_front":
            if (list.Count == 0)
            {
                outputBuilder.AppendLine("-1");
            }
            else
            {
                outputBuilder.AppendLine(list[0].ToString());
                list.RemoveAt(0);
            }
            break;

        case "pop_back":
            if (list.Count == 0)
            {
                outputBuilder.AppendLine("-1");
            }
            else
            {
                outputBuilder.AppendLine(list[^1].ToString());
                list.RemoveAt(list.Count - 1);
            }
            break;

        case "size":
            outputBuilder.AppendLine(list.Count.ToString());
            break;

        case "empty":
            outputBuilder.AppendLine(list.Count == 0 ? "1" : "0");
            break;

        case "front":
            outputBuilder.AppendLine(list.Count == 0 ? "-1" : list[0].ToString());
            break;

        case "back":
            outputBuilder.AppendLine(list.Count == 0 ? "-1" : list[^1].ToString());
            break;
    }
}

Console.Write(outputBuilder.ToString());
