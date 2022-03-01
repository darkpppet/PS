int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());

Dictionary<int, Dictionary<int, long>> routes = new();

for (int i = 1; i <= n; i++)
    routes[i] = new();

for (int i = 0; i < m; i++)
{
    string[] route = Console.ReadLine().Split();
    
    int start = int.Parse(route[0]);
    int end = int.Parse(route[1]);
    long cost = int.Parse(route[2]);
    
    routes[start][end] = routes[start].ContainsKey(end) ? Math.Min(routes[start][end], cost) : cost;
}

string[] input = Console.ReadLine().Split();

int startCity = int.Parse(input[0]);
int endCity = int.Parse(input[1]);

long[] distances = new long[n + 1];

for (int i = 1; i <= n; i++)
    distances[i] = 1_000_000_000_000;
distances[startCity] = 0;

bool[] isCheck = new bool[n + 1];

int nowNode = startCity;

for (int nodeCount = 0; nodeCount < n; nodeCount++)
{
    foreach (int nextNode in routes[nowNode].Keys)
        distances[nextNode] = Math.Min(distances[nowNode] + routes[nowNode][nextNode], distances[nextNode]);
    
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

Console.WriteLine(distances[endCity]);
