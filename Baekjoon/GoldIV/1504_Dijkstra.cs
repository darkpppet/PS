string[] input = Console.ReadLine().Split();

int n = int.Parse(input[0]);
int e = int.Parse(input[1]);

Dictionary<int, Dictionary<int, long>> graph = new();
for (int i = 1; i <= n; i++)
    graph[i] = new();

for (int i = 0; i < e; i++)
{
    input = Console.ReadLine().Split();
    
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    long c = long.Parse(input[2]);
    
    graph[a][b] = graph[a].ContainsKey(b) ? Math.Min(graph[a][b], c) : c;
    graph[b][a] = graph[b].ContainsKey(a) ? Math.Min(graph[b][a], c) : c;
}

input = Console.ReadLine().Split();
int v1 = int.Parse(input[0]);
int v2 = int.Parse(input[1]);

long[] Dijkstra(int startNode)
{
    long[] distances = new long[n + 1];
    
    for (int i = 1; i <= n; i++)
        distances[i] = 1_000_000_000_000;
    distances[startNode] = 0;
    
    bool[] isCheck = new bool[n + 1];
    
    int nowNode = startNode;
    
    for (int nodeCount = 0; nodeCount < n; nodeCount++)
    {
        foreach (int nextNode in graph[nowNode].Keys)
            distances[nextNode] = Math.Min(distances[nowNode] + graph[nowNode][nextNode], distances[nextNode]);

        isCheck[nowNode] = true;

        long min = 1_000_000_000_001;

        for (int i = 1; i <= n; i++)
        {
            if (!isCheck[i] && distances[i] < min)
            {
                min = distances[i];
                nowNode = i;
            }
        }
    }
    
    return distances;
}

long[] distances1 = Dijkstra(1);
long[] distancesV1 = Dijkstra(v1);
long[] distancesV2 = Dijkstra(v2);

long result = Math.Min(distances1[v1] + distancesV1[v2] + distancesV2[n], distances1[v2] + distancesV2[v1] + distancesV1[n]);

Console.WriteLine(result < 1_000_000_000_000 ? result : -1);
