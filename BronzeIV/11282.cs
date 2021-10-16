using System;
using System.Text;

int n = int.Parse(Console.ReadLine()) - 1;

int index0 = 234;
int index1 = 128;
int index2 = 128;

if (n < 1024)
{
	index1 = 176;
}
else
{
	index0 = 235;
	n -= 1024;
	
	index0 += n / 4096;
	n %= 4096;
}

index1 += n / 64;
index2 += n % 64;

Console.WriteLine(Encoding.UTF8.GetString(new byte[]{ (byte)index0, (byte)index1, (byte)index2 }));
