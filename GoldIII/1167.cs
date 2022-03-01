using System;
using System.Collections.Generic;
using System.Linq;

int v = int.Parse(Console.ReadLine());

Dictionary<int, Dictionary<int, int>> treeDic = new();

for (int i = 1; i <= v; i++)
{
    int[] input = Console.ReadLine().Split(' ').SkipLast(1).Select(x => int.Parse(x)).ToArray();
    
    treeDic[input[0]] = new();
    
    for (int j = 1; j < input.Count(); j += 2)
        treeDic[input[0]][input[j]] = input[j + 1];
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
