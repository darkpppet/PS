using System;
using System.Text;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

Dictionary<char, (char Left, char Right)> tree = new();

for (int i = 0; i < n; i++)
{
	string[] input = Console.ReadLine().Split(' ');
	
	tree[input[0][0]] = (input[1][0], input[2][0]);
}

void PreorderTraversal(char node, StringBuilder outputBuilder)
{
	if (node == '.')
		return;
	
	outputBuilder.Append(node);
	PreorderTraversal(tree[node].Left, outputBuilder);
	PreorderTraversal(tree[node].Right, outputBuilder);
}

void InorderTraversal(char node, StringBuilder outputBuilder)
{
	if (node == '.')
		return;
	
	InorderTraversal(tree[node].Left, outputBuilder);
	outputBuilder.Append(node);
	InorderTraversal(tree[node].Right, outputBuilder);
}

void PostorderTraversal(char node, StringBuilder outputBuilder)
{
	if (node == '.')
		return;
	
	PostorderTraversal(tree[node].Left, outputBuilder);
	PostorderTraversal(tree[node].Right, outputBuilder);
	outputBuilder.Append(node);
}

StringBuilder preorderOutputBuilder = new();
StringBuilder inorderOutputBuilder = new();
StringBuilder postorderOutputBuilder = new();

PreorderTraversal('A', preorderOutputBuilder);
InorderTraversal('A', inorderOutputBuilder);
PostorderTraversal('A', postorderOutputBuilder);

Console.WriteLine(preorderOutputBuilder.ToString());
Console.WriteLine(inorderOutputBuilder.ToString());
Console.WriteLine(postorderOutputBuilder.ToString());
