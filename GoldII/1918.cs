using System;
using System.Collections.Generic;

char[] infix = Console.ReadLine().ToCharArray();
List<char> prefix = new();
Stack<char> operatorStack = new();

foreach (char c in infix)
{
    switch (c)
    {
        case '(':
            operatorStack.Push(c);
            break;
            
        case ')':
            for (char tempc = operatorStack.Peek(); tempc != '('; tempc = operatorStack.Peek())
                prefix.Add(operatorStack.Pop());
            operatorStack.Pop();
            break;
            
        case '*': case '/':
            if (operatorStack.Count > 0)
            {
                char tempc = operatorStack.Peek();
                while (tempc != '(' && tempc != '+' && tempc != '-')
                {
                    prefix.Add(operatorStack.Pop());
                    
                    if (operatorStack.Count > 0)
                        tempc = operatorStack.Peek();
                    else
                        break;
                }
            }
            operatorStack.Push(c);
            break;
        
        case '+': case '-':
            if (operatorStack.Count > 0)
            {
                char tempc = operatorStack.Peek();
                while (tempc != '(')
                {
                    prefix.Add(operatorStack.Pop());
                    
                    if (operatorStack.Count > 0)
                        tempc = operatorStack.Peek();
                    else
                        break;
                }
            }
            operatorStack.Push(c);
            break;
            
        default:
            prefix.Add(c);
            break;
    }
}

while (operatorStack.Count > 0)
    prefix.Add(operatorStack.Pop());

Console.WriteLine(new string(prefix.ToArray()));
