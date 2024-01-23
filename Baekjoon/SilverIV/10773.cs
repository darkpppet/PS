using System;
using System.Collections.Generic;
using System.Linq;

Stack<int> stack = new();

int count = int.Parse(Console.ReadLine());

for (int i = 0; i < count; i++)
{
    int num = int.Parse(Console.ReadLine());

    if (num == 0)
        stack.Pop();
    else
        stack.Push(num);
}

Console.WriteLine(stack.Sum());
