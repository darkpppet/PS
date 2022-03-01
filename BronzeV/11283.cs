using System;
using System.Text;

int[] code = Array.ConvertAll(Encoding.UTF8.GetBytes(Console.ReadLine()), x => (int)x);

int count = code[2] - 127;

if (code[0] == 234)
	count += (code[1] - 176) * 64;
else
	count += 1024 + (code[0] - 235) * 4096 + (code[1] - 128) * 64;

Console.WriteLine(count);
