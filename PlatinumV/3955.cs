using System;
using System.Text;

static class Candy
{
    public static bool IsCoPrime(int a, int b)
    {
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        
        if (a == 1)
            return true;
        else
            return false;
    }
    
    public static (int Y, int X) Solve(int c, int k)
    {
        int y2 = 1;
        int y1 = 0;
        
        int x2 = 0;
        int x1 = 1;
        
        int r2 = c;
        int r1 = k;
        
        int q1 = r2 / r1;
        
        while (true)
        {
            int r0 = r2 % r1;
            if (r0 == 0)
                break;
            
            int y0 = y2 - y1 * q1;
            int x0 = x2 - x1 * q1;
            int q0 = r1 / r0;
            
            x2 = x1;
            x1 = x0;
            
            y2 = y1;
            y1 = y0;
            
            q1 = q0;
            
            r2 = r1;
            r1 = r0;
        }
        
        return (y1, -x1);
    }
}

class Program
{
    static void Main(string[] args)
    {
        StringBuilder outputBuilder = new();
        
        int countT = int.Parse(Console.ReadLine());
         
        for (int count = 0; count < countT; count++)
        {
            string[] input = Console.ReadLine().Split(' ');
	
            int k = int.Parse(input[0]);
            int c = int.Parse(input[1]);
            
            if (!Candy.IsCoPrime(k, c))
            {
                outputBuilder.AppendLine("IMPOSSIBLE");
                continue;
            }
            
            (int y, int x) = Candy.Solve(c, k);
            
            while (y > 1_000_000_000)
            {
                x -= c;
                y -= k;
            }
            
            while (x <= 0 || y <= 0)
            {
                x += c;
                y += k;
            }
            
            if (y > 1_000_000_000)
            {
                outputBuilder.AppendLine("IMPOSSIBLE");
            }
            else
            {
                outputBuilder.AppendLine(y.ToString());
            }
        }
        
        Console.Write(outputBuilder.ToString());
    }
}
