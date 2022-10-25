using System.Text;

string[] input = Console.ReadLine().Split();

int v = int.Parse(input[0]);
int e = int.Parse(input[1]);

int k = int.Parse(Console.ReadLine());

Dictionary<int, Dictionary<int, int>> dic = new();

for (int i = 1; i < v + 1; i++)
    dic[i] = new();

for (int i = 0; i < e; i++)
{
    input = Console.ReadLine().Split();
    
    int startNode = int.Parse(input[0]);
    int endNode = int.Parse(input[1]);
    int length = int.Parse(input[2]);
    
    if (dic[startNode].ContainsKey(endNode))
        dic[startNode][endNode] = Math.Min(dic[startNode][endNode], length);
    else
        dic[startNode][endNode] = length;
}

int[] distances = new int[v + 1];

for (int i = 1; i < v + 1; i++)
    distances[i] = 30_000_000;
distances[k] = 0;

bool[] isCheck = new bool[v + 1];

int nowNode = k;

for (int nodeCount = 0; nodeCount < v; nodeCount++)
{
    foreach (int nextNode in dic[nowNode].Keys)
        distances[nextNode] = Math.Min(distances[nowNode] + dic[nowNode][nextNode], distances[nextNode]);
    
    isCheck[nowNode] = true;
    
    int min = 30_000_001;
    
    for (int i = 1; i < v + 1; i++)
    {
        if (!isCheck[i] && distances[i] < min)
        {
            min = distances[i];
            nowNode = i;
        }
    }
}

StringBuilder outputBuilder = new();

for (int i = 1; i < v + 1; i++)
    outputBuilder.AppendLine(distances[i] != 30_000_000 ? distances[i].ToString() : "INF");

Console.Write(outputBuilder.ToString());
