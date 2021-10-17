using System;
using System.Text;
using System.Collections.Generic;

Stack<int> stack = new();
StringBuilder outputBuilder = new();

bool isNo = false;

int count = int.Parse(Console.ReadLine());

int before = 0;
int nownum = 1;

for (int i = 0; i < count; i++)
{
    int num = int.Parse(Console.ReadLine());

    if (num > before)
    {
        while (nownum <= num)
        {
            stack.Push(nownum++);
            outputBuilder.Append("+\n");
        }
    }

    if (num == stack.Pop())
        outputBuilder.Append("-\n");
    else
        isNo = true;

    before = num;

    if (isNo)
        break;
}

Console.WriteLine(isNo ? "NO" : outputBuilder.ToString());
