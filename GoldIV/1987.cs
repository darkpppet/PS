using System;
using System.Collections.Generic;

string[] input = Console.ReadLine().Split(' ');

int r = int.Parse(input[0]);
int c = int.Parse(input[1]);
	
char[,] board = new char[r, c];
	
for (int i = 0; i < r; i++)
{
	string row = Console.ReadLine();
	
	for (int j = 0; j < c; j++)
		board[i, j] = row[j];
}

Stack<char> stack = new();





