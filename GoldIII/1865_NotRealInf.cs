int tc = int.Parse(Console.ReadLine());

for (int tcCount = 0; tcCount < tc; tcCount++)
{
    string[] input = Console.ReadLine().Split();
    
    int n = int.Parse(input[0]);
    int m = int.Parse(input[1]);
    int w = int.Parse(input[2]);
    
    Dictionary<int, Dictionary<int, int>> graph = new();
    
    for (int i = 1; i <= n; i++)
        graph[i] = new();
    
    for (int i = 0; i < m; i++)
    {
        input = Console.ReadLine().Split();
        
        int s = int.Parse(input[0]);
        int e = int.Parse(input[1]);
        int t = int.Parse(input[2]);
        
        graph[s][e] = graph[s].ContainsKey(e) ? Math.Min(graph[s][e], t) : t;
        graph[e][s] = graph[e].ContainsKey(s) ? Math.Min(graph[e][s], t) : t;
    }
    
    for (int i = 0; i < w; i++)
    {
        input = Console.ReadLine().Split();
        
        int s = int.Parse(input[0]);
        int e = int.Parse(input[1]);
        int t = -int.Parse(input[2]);
        
        graph[s][e] = graph[s].ContainsKey(e) ? Math.Min(graph[s][e], t) : t;
    }
    
    int[] distance = Enumerable.Repeat(50_000_000, n + 1).ToArray();
    distance[1] = 0;
    
    for (int i = 1; i <= n - 1; i++)
    {
        foreach (int startNode in graph.Keys)
        {
            foreach (int destNode in graph[startNode].Keys)
            {
                if (distance[startNode] + graph[startNode][destNode] < distance[destNode])
                    distance[destNode] = distance[startNode] + graph[startNode][destNode];
            }
        }
    }
    
    bool canTimeLeap = false;
    
    foreach (int startNode in graph.Keys)
    {
        foreach (int destNode in graph[startNode].Keys)
        {
            if (distance[startNode] + graph[startNode][destNode] < distance[destNode])
                canTimeLeap = true;
        }
    }
    
    Console.WriteLine(canTimeLeap ? "YES" : "NO");
}
