using System;

int[] fruits1 = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);
int[] fruits2 = Array.ConvertAll(Console.ReadLine().Split(" "), int.Parse);

int count1 = fruits1[0] + fruits2[1];
int count2 = fruits1[1] + fruits2[0];

Console.WriteLine(count1 < count2 ? count1 : count2);
