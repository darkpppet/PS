using System;

int[] birthday = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] nowday = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

int manOld = nowday[0] - birthday[0] - 1;

if (birthday[1] == nowday[1])
	manOld += birthday[2] <= nowday[2] ? 1 : 0;
else
	manOld += birthday[1] < nowday[1] ? 1 : 0;

Console.WriteLine(manOld);
Console.WriteLine(nowday[0] - birthday[0] + 1);
Console.WriteLine(nowday[0] - birthday[0]);
