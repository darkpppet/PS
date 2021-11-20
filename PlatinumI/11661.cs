using System;

class Solver
{
    public static void Swap(ref long a, ref long b)
    {
        long temp = a;
        a = b;
        b = temp;
    }
    
    public static long CalcGcd(long a, long b)
    {
        a = Math.Abs(a);
        b = Math.Abs(b);
        
        if (a < b)
            Swap(ref a, ref b);

        while (b != 0)
        {
            long r = a % b;
            a = b;
            b = r;
        }
        
        return a;
    }
    
    public static (long X, long Y) Solve(long a, long b)
    {
        long x2 = 1;
        long x1 = 0;
        
        long y2 = 0;
        long y1 = 1;
        
        long r2 = a;
        long r1 = b;
        
        long q1 = r2 / r1;
        
        while (true)
        {
            long r0 = r2 % r1;
            if (r0 == 0)
                break;
            
            long x0 = x2 - x1 * q1;
            long y0 = y2 - y1 * q1;
            long q0 = r1 / r0;
            
            x2 = x1;
            x1 = x0;
            
            y2 = y1;
            y1 = y0;
            
            q1 = q0;
            
            r2 = r1;
            r1 = r0;
        }
        
        return (x1, y1);
    }
}

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');

        long a = long.Parse(input[0]);
        long b = long.Parse(input[1]);
        long c = -long.Parse(input[2]);
        long x1 = long.Parse(input[3]);
        long x2 = long.Parse(input[4]);
        long y1 = long.Parse(input[5]);
        long y2 = long.Parse(input[6]);
        
        if (x1 > x2 || y1 > y2)
        {
            Console.WriteLine(0);
        }
        else if (a == 0 && b == 0)
        {
            if (c == 0)
                Console.WriteLine((x2 - x1 + 1) * (y2 - y1 + 1));
            else
                Console.WriteLine(0);
        }
        else if (a == 0)
        {
            if (c % b == 0 && c / b >= y1 && c / b <= y2)
                Console.WriteLine(x2 - x1 + 1);
            else
                Console.WriteLine(0);
        }
        else if (b == 0)
        {
            if (c % a == 0 && c / a >= x1 && c / a <= x2)
                Console.WriteLine(y2 - y1 + 1);
            else
                Console.WriteLine(0);
        }
        else if (c == 0)
        {
            if (x1 <= 0 && x2 >= 0 && y1 <= 0 && y2 >= 0)
                Console.WriteLine(1);
            else
                Console.WriteLine(0);
        }
        else if (c % Solver.CalcGcd(a, b) != 0)
        {
            Console.WriteLine(0);
        }
        else
        {
            (long x0, long y0) = Solver.Solve(a, b);

            long d = a * x0 + b * y0;
            
            x0 = x0 * c / d;
            y0 = y0 * c / d;

            long kx = b / d;
            long ky = -a / d;

            x1 -= x0;
            x2 -= x0;

            if (kx < 0)
                Solver.Swap(ref x1, ref x2);

            x1 = (long)Math.Ceiling((double)x1 / kx);
            x2 = (long)Math.Floor((double)x2 / kx);

            y1 -= y0;
            y2 -= y0;

            if (ky < 0)
                Solver.Swap(ref y1, ref y2);

            y1 = (long)Math.Ceiling((double)y1 / ky);
            y2 = (long)Math.Floor((double)y2 / ky);

            long left = Math.Max(x1, y1);
            long right = Math.Min(x2, y2);

            if (right >= left)
                Console.WriteLine(right - left + 1);
            else
                Console.WriteLine(0);
        }
    }
}
