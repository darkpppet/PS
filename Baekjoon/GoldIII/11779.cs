using System.Text;

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
int[] beforeCity = new int[n + 1];

int nowCity = startCity;

for (int nodeCount = 0; nodeCount < n; nodeCount++)
{
    foreach (int nextCity in routes[nowCity].Keys)
    {
        if (distances[nowCity] + routes[nowCity][nextCity] < distances[nextCity])
        {
            distances[nextCity] = distances[nowCity] + routes[nowCity][nextCity];
            beforeCity[nextCity] = nowCity;
        }
    }
    
    isCheck[nowCity] = true;
    
    long min = 1_000_000_000_001;
    
    for (int i = 1; i <= n; i++)
    {
        if (!isCheck[i] && distances[i] < min)
        {
            min = distances[i];
            nowCity = i;
        }
    }
}

nowCity = endCity;

List<int> minCostRoute = new();

while (nowCity != startCity)
{
    minCostRoute.Add(nowCity);
    nowCity = beforeCity[nowCity];
}
    
minCostRoute.Add(startCity);

minCostRoute.Reverse();

StringBuilder outputBuilder = new();

outputBuilder.AppendLine(distances[endCity].ToString());
outputBuilder.AppendLine(minCostRoute.Count.ToString());

foreach (int city in minCostRoute)
    outputBuilder.Append($"{city} ");

Console.WriteLine(outputBuilder.ToString());
