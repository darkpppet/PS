using System;
using System.Collections.Generic;

char[] infix = Console.ReadLine().ToCharArray();
List<char> prefix = new();

Stack<char> operatorStack = new();

foreach (char c in input)
{
    char top = operatorStack.Peek();
    
    switch (c)
    {
        case '(':
            operatorStack.Push(c);
            break;
            
        case ')':
            char tempc;
            break;
            
        case '*': case '/':
            if (top == '(' ||top == '+' || top == '-')
                operatorStack.Push(c);
            else
                prefix.Add(operatorStack.Pop());
                    
                
            break;
        
        case '+': case '-':
            break;
            
        default:
            prefix.Add(c);
            break;
    }
    
    
}




