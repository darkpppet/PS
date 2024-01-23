using System;
using System.Text;
using System.Collections.Generic;

static class Prime
{
    public static long CalcGcd(long a, long b)
    {
    }
    
    public static bool isPrime(long n)
    {
        
        
    }
    
    private long F(long x, long n) => (x * x) % n;
    
    public static List<long> Factorize(long n)
    {
        
        
    }
    
}

class Program
{
    static void Main(string[] args)
    {
        long n = long.Parse(Console.ReadLine());
        
        List<long> primes = Prime.Factorize(n);
        
        primes.Sort();
        
        StringBuilder outputBuilder = new();
        
        foreach (long prime in primes)
            outputBuilder.AppendLine(prime.ToString());
        
        Console.WriteLine(outputBuilder.ToString());
    }
}
