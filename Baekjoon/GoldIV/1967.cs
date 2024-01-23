using System;
using System.Collections.Generic;

int n = int.Parse(Console.ReadLine());

Dictionary<int, Dictionary<int, int>> treeDic = new();

for (int i = 1; i <= n; i++)
    treeDic[i] = new() { [i] = 0 };

for (int i = 0; i < n - 1; i++)
{
    string[] input = Console.ReadLine().Split(' ');
    
    int parentNode = int.Parse(input[0]);
    int childNode = int.Parse(input[1]);
    int length = int.Parse(input[2]);
    
    treeDic[parentNode][childNode] = length;
    treeDic[childNode][parentNode] = length;
}

HashSet<int> history = new();

(int Node, int Length) Dfs(int nowNode, int lengthSum)
{
    history.Add(nowNode);
    int resultNode = nowNode;
    int resultLength = lengthSum;
    
    foreach (int nextNode in treeDic[nowNode].Keys)
    {
        if (!history.Contains(nextNode))
        {
            (int tempNode, int tempLength) = Dfs(nextNode, lengthSum + treeDic[nowNode][nextNode]);
            
            if (tempLength > resultLength)
            {
                resultLength = tempLength;
                resultNode = tempNode;
            }
        }
    }
    
    history.Remove(nowNode);
    return (resultNode, resultLength);
}

(int farthestNode, _) = Dfs(1, 0);
(_, int diameter) = Dfs(farthestNode, 0);

Console.WriteLine(diameter);
